// COMSC-210 | Lab 20 | Ali Saeed
// ide used: vs code / vim

#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

const int MIN = 10000, MAX = 99999;
double price = (rand() % (MAX-MIN+1) + MIN) / (double) 100;

class Chair {
private:
    int legs;
    double * prices;
public:
// constructors
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2 == 0) ? 3 : 4;
        for (int i = 0; i < SIZE; i++)
            prices[i] = price;
    }
    Chair(int l, double inputPrices[]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = inputPrices[i];
    }

    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    //first constructor without parameters
    Chair *chairPtr = new Chair;
    chairPtr->print();

    //creating dynamic chair object with constructor using parameterts
    double livingChairPrices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, livingChairPrices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    double firstPrices[SIZE] = {441.41, 552.52, 663.63};
    collection[0] = Chair(4, firstPrices);
    double secondPrices[SIZE] = {484.84, 959.59, 868.68};
    collection[1] = Chair(4, secondPrices);
    double thirdPrices[SIZE] = {626.26, 515.15, 757.57};
    collection[2] = Chair(4, thirdPrices);

    for (int i = 0; i < SIZE; i++)
        collection[i].print();
        
    return 0;
}
