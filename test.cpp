#include<iostream>
using namespace std;

class Gates{
public:
    int input_num (){
        int num;
        cout << "Enter number of inputs: ";
        cin >> num;
        while (num > 4 || num < 1)
        {
            cout<< "Number should be between 1 and 4. Reenter the Number: ";
            cin>> num;
        }
        return num;
    }
    void input_values (int num, int values[]){
        for (int i = 0; i < num; i++) {
            cout << "Enter the value for input " << i + 1 << ": ";
            cin >> values[i];
            while (values[i] != 0 && values[i] != 1) {
                cout << "Invalid input. Please enter 0 or 1: ";
                cin >> values[i];
            }
        }
    }
    void display_values (int num, int values[]){
        for (int i = 0; i < num; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
    void AND_gate(int num, int values[]){
        int result = 1;
        for (int i = 0; i < num; i++) {
            result &= values[i];
        }
        cout << "AND Gate Result: " << result << endl;
    }
    void OR_gate(int num, int values[]){
        int result = 0;
        for (int i = 0; i < num; i++) {
            result |= values[i];
        }
        cout << "OR Gate Result: " << result << endl;
    }
    void NOT_gate(int value){
        cout << "NOT Gate Result: " << !value << endl;
    }
    void XOR_gate(int num, int values[]){
        int result = 0;
        for (int i = 0; i < num; i++) {
            result ^= values[i];
        }
        cout << "XOR Gate Result: " << result << endl;
    }
    void NAND_gate(int num, int values[]){
        int result = 1;
        for (int i = 0; i < num; i++) {
            result &= values[i];
        }
        cout << "NAND Gate Result: " << !result << endl;
    }
    void NOR_gate(int num, int values[]){
        int result = 0;
        for (int i = 0; i < num; i++) {
            result |= values[i];
        }
        cout << "NOR Gate Result: " << !result << endl;
    }
    void XNOR_gate(int num, int values[]){
        int result = 0;
        for (int i = 0; i < num; i++) {
            result ^= values[i];
        }
        cout << "XNOR Gate Result: " << !result << endl;
    }
    void display_menu(){
        cout << "Select the gate operation you want to perform:" << endl;
        cout << "1. AND Gate" << endl;
        cout << "2. OR Gate" << endl;
        cout << "3. NOT Gate" << endl;
        cout << "4. XOR Gate" << endl;
        cout << "5. NAND Gate" << endl;
        cout << "6. NOR Gate" << endl;
        cout << "7. XNOR Gate" << endl;
    }
    void perform_operation(int choice, int num, int values[]){
        switch (choice) {
            case 1:
                AND_gate(num, values);
                break;
            case 2:
                OR_gate(num, values);
                break;
            case 3:
                if (num == 1) {
                    NOT_gate(values[0]);
                } else {
                    cout << "NOT gate requires exactly one input." << endl;
                }
                break;
            case 4:
                XOR_gate(num, values);
                break;
            case 5:
                NAND_gate(num, values);
                break;
            case 6:
                NOR_gate(num, values);
                break;
            case 7:
                XNOR_gate(num, values);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
};
int main() {
    Gates gate;
    
    int num = gate.input_num();
    
    int values[4];
    gate.input_values(num, values);
    
    cout << "The values entered are: ";
    gate.display_values(num, values);
    
    gate.display_menu();
    
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    
    gate.perform_operation(choice, num, values);
    
    return 0;
}