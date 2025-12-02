#include <iostream>
using namespace std;

struct PolyTerm {
    int coeff;
    int exp;
    PolyTerm* next;
};

// Create new term
PolyTerm* createTerm(int coeff, int exp) {
    PolyTerm* newTerm = new PolyTerm;
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = nullptr;
    return newTerm;
}

// Insert term in polynomial
void insertTerm(PolyTerm* &poly, int coeff, int exp) {
    if(coeff == 0) return;
    
    PolyTerm* newTerm = createTerm(coeff, exp);
    
    // If polynomial is empty or new term has highest exponent
    if(poly == nullptr || exp > poly->exp) {
        newTerm->next = poly;
        poly = newTerm;
        return;
    }
    
    PolyTerm* curr = poly;
    PolyTerm* prev = nullptr;
    
    // Find appropriate position
    while(curr != nullptr && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }
    
    // If same exponent exists, add coefficients
    if(curr != nullptr && curr->exp == exp) {
        curr->coeff += coeff;
        delete newTerm;
        if(curr->coeff == 0) {
            if(prev != nullptr) {
                prev->next = curr->next;
            } else {
                poly = curr->next;
            }
            delete curr;
        }
        return;
    }
    
    // Insert new term
    newTerm->next = curr;
    if(prev != nullptr) {
        prev->next = newTerm;
    } else {
        poly = newTerm;
    }
}

// Display polynomial
void displayPoly(PolyTerm* poly) {
    if(poly == nullptr) {
        cout << "0\n";
        return;
    }
    
    PolyTerm* temp = poly;
    bool first = true;
    
    while(temp != nullptr) {
        if(!first && temp->coeff > 0) cout << " + ";
        if(temp->coeff < 0) cout << " - ";
        
        int absCoeff = (temp->coeff > 0) ? temp->coeff : -temp->coeff;
        
        if(absCoeff != 1 || temp->exp == 0) {
            if(!first) cout << absCoeff;
            else cout << temp->coeff;
        }
        
        if(temp->exp > 0) {
            cout << "x";
            if(temp->exp > 1) cout << "^" << temp->exp;
        }
        
        first = false;
        temp = temp->next;
    }
    cout << endl;
}

// Add two polynomials
PolyTerm* addPolynomials(PolyTerm* poly1, PolyTerm* poly2) {
    PolyTerm* result = nullptr;
    PolyTerm* p1 = poly1;
    PolyTerm* p2 = poly2;
    
    while(p1 != nullptr && p2 != nullptr) {
        if(p1->exp > p2->exp) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if(p1->exp < p2->exp) {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            if(sumCoeff != 0) {
                insertTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // Add remaining terms
    while(p1 != nullptr) {
        insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    
    while(p2 != nullptr) {
        insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    
    return result;
}

// Multiply two polynomials
PolyTerm* multiplyPolynomials(PolyTerm* poly1, PolyTerm* poly2) {
    PolyTerm* result = nullptr;
    
    for(PolyTerm* p1 = poly1; p1 != nullptr; p1 = p1->next) {
        for(PolyTerm* p2 = poly2; p2 != nullptr; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            insertTerm(result, coeff, exp);
        }
    }
    
    return result;
}

// Free memory
void deletePoly(PolyTerm* &poly) {
    PolyTerm* curr = poly;
    while(curr != nullptr) {
        PolyTerm* next = curr->next;
        delete curr;
        curr = next;
    }
    poly = nullptr;
}

int main() {
    PolyTerm* poly1 = nullptr;
    PolyTerm* poly2 = nullptr;
    
    // Create polynomial 1: 3x^3 + 2x^2 + 5
    insertTerm(poly1, 3, 3);
    insertTerm(poly1, 2, 2);
    insertTerm(poly1, 5, 0);
    
    // Create polynomial 2: 4x^3 - 2x^2 + x - 1
    insertTerm(poly2, 4, 3);
    insertTerm(poly2, -2, 2);
    insertTerm(poly2, 1, 1);
    insertTerm(poly2, -1, 0);
    
    cout << "Polynomial 1: ";
    displayPoly(poly1);
    
    cout << "Polynomial 2: ";
    displayPoly(poly2);
    
    PolyTerm* sum = addPolynomials(poly1, poly2);
    cout << "\nSum: ";
    displayPoly(sum);
    
    PolyTerm* product = multiplyPolynomials(poly1, poly2);
    cout << "Product: ";
    displayPoly(product);
    
    deletePoly(poly1);
    deletePoly(poly2);
    deletePoly(sum);
    deletePoly(product);
    
    return 0;
}
