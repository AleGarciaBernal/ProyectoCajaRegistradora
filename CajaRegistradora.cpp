#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define length(x) (sizeof(x) / sizeof(x[0]))
using namespace std;
int option; 
int montoAPagar, pago, cambio;
int coins[]={1, 2, 5, 10, 20, 50, 100, 200};

int dp[9][1000];
int coinChange(int value){
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= value; i++){
        dp[0][i] = 0;
    } 
    for (int i = 0; i < length(coins); i++){
        dp[i][0] = 1;
    }
    for (int i = 1; i <= length(coins); i++){
        for (int j = 0; j <= value; j++){
            if(j - coins[i-1] >= 0){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }    
        }   
    }
    return dp[length(coins)][value];
}

vector<int> manera;
void printChanges(int i, int j){
    if(dp[i][j] == 0){
        return;
    }
    if(j == 0){
        for (int i = 0; i < manera.size(); i++){
            cout << "[" << manera[i] << "]";
        }
        cout << endl;
        return;
    }
    if(dp[i][j] > dp[i-1][j]){
        manera.push_back(coins[i-1]);
        printChanges(i, j-coins[i-1]);
        manera.pop_back();
    }
    printChanges(i-1, j);
}

long long dpMin[1000000];
long long coinChangeMin(long long value){
    if(value == 0){
        return 0;
    }
    if(dpMin[value] == -1){
        long long minValue = 1e9;
        for (int i = 0; i < length(coins); i++){
            if(value - coins[i] >= 0){
                minValue = min(minValue, 1 + coinChangeMin(value - coins[i]));
            }
        }
        dpMin[value] = minValue;
    }
    return dpMin[value];
}

void printMenu() {
    cout<<"====================================================="<<endl;
    cout<<"1. Ejecutar el Primer Ejemplo"<<endl;
    cout<<"2. Ejecutar el Segundo Ejemplo"<<endl;
    cout<<"3. Ejecutar el Tercer Ejemplo"<<endl;
    cout<<"4. Ejecutar el Cuarto Ejemplo"<<endl;
    cout<<"5. Ejecutar el Quinto Ejemplo"<<endl;
    cout<<"6. Ejecutar el Sexto Ejemplo"<<endl;
    cout<<"7. Ejecutar tu propio Ejemplo"<<endl;
    cout<<"X. Salir del programa"<<endl;
    cout<<"====================================================="<<endl;
}

void ejemploAri1() {
    montoAPagar = 242;
    pago = 250;
    cambio = pago - montoAPagar;
    if(cambio != 0){
        cout<<"====================================================="<<endl;
        cout<<"11. Mostrar cuanto es el cambio de que debe dar el cajero"<<endl;
        cout<<"12. Mostrar la minima cantidad de monedas y/o billetes usados para dar el cambio"<<endl;
        cout<<"13. Mostrar cuantas maneras de dar el cambio existen"<<endl;
        cout<<"====================================================="<<endl;
        cin >> option;
        switch(option) {
        case 11:
            cout << "Monto a pagar: " << montoAPagar << endl;
            cout << "Monto pagado: " << pago << endl;
            cout << "El cajero debe dar de cambio " << cambio << " Bs." << endl;
            break;
        case 12:
            cout << "La minima cantidad de monedas y/o billetes usados para dar el cambio es " << coinChangeMin(cambio) << "." << endl;
            break;
        case 13:
            cout << "Existen " << coinChange(cambio) << " maneras de dar el cambio, desea verlas?" << endl;
            cout << "14. SI"<<endl;
            cout << "15. NO"<<endl;
            cin >> option;
            switch(option) {
                case 14:
                    printChanges(length(coins), cambio);
                case 15:
                    break;
            }
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
    } else {
        cout << "El cajero no debe dar cambio." << endl;
    }
}

void ejemploAri2() {
    montoAPagar = 10;
    pago = 15;
    cambio = pago - montoAPagar;
    if(cambio != 0){
        cout<<"====================================================="<<endl;
        cout<<"11. Mostrar cuanto es el cambio de que debe dar el cajero"<<endl;
        cout<<"12. Mostrar la minima cantidad de monedas y/o billetes usados para dar el cambio"<<endl;
        cout<<"13. Mostrar las maneras de dar el cambio"<<endl;
        cout<<"====================================================="<<endl;
        cin >> option;
        switch(option) {
        case 11:
            cout << "Monto a pagar: " << montoAPagar << endl;
            cout << "Monto pagado: " << pago << endl;
            cout << "El cajero debe dar de cambio " << cambio << " Bs." << endl;
            break;
        case 12:
            cout << "La minima cantidad de monedas y/o billetes usados para dar el cambio es " << coinChangeMin(cambio) << "." << endl;
            break;
        case 13:
            cout << "Existen " << coinChange(cambio) << " maneras de dar el cambio, desea verlas?" << endl;
            cout << "14. SI"<<endl;
            cout << "15. NO"<<endl;
            cin >> option;
            switch(option) {
                case 14:
                    printChanges(length(coins), cambio);
                case 15:
                    break;
            }
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
    } else {
        cout << "El cajero no debe dar cambio." << endl;
    }
}

void ejemploXime1() {
    montoAPagar = 98;
    pago = 200;
    cambio = pago - montoAPagar;
    if(cambio != 0){
        cout<<"====================================================="<<endl;
        cout<<"11. Mostrar cuanto es el cambio de que debe dar el cajero"<<endl;
        cout<<"12. Mostrar la minima cantidad de monedas y/o billetes usados para dar el cambio"<<endl;
        cout<<"13. Mostrar las maneras de dar el cambio"<<endl;
        cout<<"====================================================="<<endl;
        cin >> option;
        switch(option) {
        case 11:
            cout << "Monto a pagar: " << montoAPagar << endl;
            cout << "Monto pagado: " << pago << endl;
            cout << "El cajero debe dar de cambio " << cambio << " Bs." << endl;
            break;
        case 12:
            cout << "La minima cantidad de monedas y/o billetes usados para dar el cambio es " << coinChangeMin(cambio) << "." << endl;
            break;
        case 13:
            cout << "Existen " << coinChange(cambio) << " maneras de dar el cambio, desea verlas?" << endl;
            cout << "14. SI"<<endl;
            cout << "15. NO"<<endl;
            cin >> option;
            switch(option) {
                case 14:
                    printChanges(length(coins), cambio);
                case 15:
                    break;
            }
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
    } else {
        cout << "El cajero no debe dar cambio." << endl;
    }
}

void ejemploXime2() {
    montoAPagar = 35;
    pago = 50;
    cambio = pago - montoAPagar;
    if(cambio != 0){
        cout<<"====================================================="<<endl;
        cout<<"11. Mostrar cuanto es el cambio de que debe dar el cajero"<<endl;
        cout<<"12. Mostrar la minima cantidad de monedas y/o billetes usados para dar el cambio"<<endl;
        cout<<"13. Mostrar las maneras de dar el cambio"<<endl;
        cout<<"====================================================="<<endl;
        cin >> option;
        switch(option) {
        case 11:
            cout << "Monto a pagar: " << montoAPagar << endl;
            cout << "Monto pagado: " << pago << endl;
            cout << "El cajero debe dar de cambio " << cambio << " Bs." << endl;
            break;
        case 12:
            cout << "La minima cantidad de monedas y/o billetes usados para dar el cambio es " << coinChangeMin(cambio) << "." << endl;
            break;
        case 13:
            cout << "Existen " << coinChange(cambio) << " maneras de dar el cambio, desea verlas?" << endl;
            cout << "14. SI"<<endl;
            cout << "15. NO"<<endl;
            cin >> option;
            switch(option) {
                case 14:
                    printChanges(length(coins), cambio);
                case 15:
                    break;
            }
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
    } else {
        cout << "El cajero no debe dar cambio." << endl;
    }
}

void ejemploAle1() {
    montoAPagar = 89;
    pago = 100;
    cambio = pago - montoAPagar;
    if(cambio != 0){
        cout<<"====================================================="<<endl;
        cout<<"11. Mostrar cuanto es el cambio de que debe dar el cajero"<<endl;
        cout<<"12. Mostrar la minima cantidad de monedas y/o billetes usados para dar el cambio"<<endl;
        cout<<"13. Mostrar las maneras de dar el cambio"<<endl;
        cout<<"====================================================="<<endl;
        cin >> option;
        switch(option) {
        case 11:
            cout << "Monto a pagar: " << montoAPagar << endl;
            cout << "Monto pagado: " << pago << endl;
            cout << "El cajero debe dar de cambio " << cambio << " Bs." << endl;
            break;
        case 12:
            cout << "La minima cantidad de monedas y/o billetes usados para dar el cambio es " << coinChangeMin(cambio) << "." << endl;
            break;
        case 13:
            cout << "Existen " << coinChange(cambio) << " maneras de dar el cambio, desea verlas?" << endl;
            cout << "14. SI"<<endl;
            cout << "15. NO"<<endl;
            cin >> option;
            switch(option) {
                case 14:
                    printChanges(length(coins), cambio);
                case 15:
                    break;
            }
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
    } else {
        cout << "El cajero no debe dar cambio." << endl;
    }
}

void ejemploAle2() {
    montoAPagar = 121;
    pago = 140;
    cambio = pago - montoAPagar;
    if(cambio != 0){
        cout<<"====================================================="<<endl;
        cout<<"11. Mostrar cuanto es el cambio de que debe dar el cajero"<<endl;
        cout<<"12. Mostrar la minima cantidad de monedas y/o billetes usados para dar el cambio"<<endl;
        cout<<"13. Mostrar las maneras de dar el cambio"<<endl;
        cout<<"====================================================="<<endl;
        cin >> option;
        switch(option) {
        case 11:
            cout << "Monto a pagar: " << montoAPagar << endl;
            cout << "Monto pagado: " << pago << endl;
            cout << "El cajero debe dar de cambio " << cambio << " Bs." << endl;
            break;
        case 12:
            cout << "La minima cantidad de monedas y/o billetes usados para dar el cambio es " << coinChangeMin(cambio) << "." << endl;
            break;
        case 13:
            cout << "Existen " << coinChange(cambio) << " maneras de dar el cambio, desea verlas?" << endl;
            cout << "14. SI"<<endl;
            cout << "15. NO"<<endl;
            cin >> option;
            switch(option) {
                case 14:
                    printChanges(length(coins), cambio);
                case 15:
                    break;
            }
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
    } else {
        cout << "El cajero no debe dar cambio." << endl;
    }
}

void ejemploPropio(int pago, int montoAPagar) {
    cambio = pago - montoAPagar;
    cout<<"====================================================="<<endl;
    cout<<"11. Mostrar cuanto es el cambio de que debe dar el cajero"<<endl;
    cout<<"12. Mostrar la minima cantidad de monedas y/o billetes usados para dar el cambio"<<endl;
    cout<<"13. Mostrar las maneras de dar el cambio"<<endl;
    cout<<"====================================================="<<endl;
    cin >> option;
    switch(option) {
        case 11:
            cout << "Monto a pagar: " << montoAPagar << endl;
            cout << "Monto pagado: " << pago << endl;
            cout << "El cajero debe dar de cambio " << cambio << " Bs." << endl;
            break;
        case 12:
            cout << "La minima cantidad de monedas y/o billetes usados para dar el cambio es " << coinChangeMin(cambio) << "." << endl;
            break;
        case 13:
            cout << "Existen " << coinChange(cambio) << " maneras de dar el cambio, desea verlas?" << endl;
            cout << "14. SI"<<endl;
            cout << "15. NO"<<endl;
            cin >> option;
            switch(option) {
                case 14:
                    printChanges(length(coins), cambio);
                case 15:
                    break;
            }
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
    }
}

void salir() {
    cout<<"Saliendo del Programa"<<endl;
}

int main() {
    //input;
    memset(dpMin, -1, sizeof(dpMin));
    printMenu();
    cin >> option;
    do {
        switch(option) {
        case 1:
            ejemploAri1();
            break;
        case 2:
            ejemploAri2();
            break;
        case 3:
            ejemploXime1();
            break;
        case 4:
            ejemploXime2();
            break;
        case 5:
            ejemploAle1();
            break;
        case 6:
            ejemploAle2();
            break;
        case 7:
            cout<<"====================================================="<<endl;
            cout << "Introduzca el monto a pagar:" << endl;
            cout<<"====================================================="<<endl;
            cin >> montoAPagar;
            cout<<"====================================================="<<endl;
            cout << "Introduzca el monto pagado:" << endl;
            cout<<"====================================================="<<endl;
            cin >> pago;
            ejemploPropio(pago, montoAPagar);
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
        printMenu();
    } 
    while (cin >> option && option);
    salir();
}
  