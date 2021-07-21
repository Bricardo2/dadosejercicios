#include <iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;
//cifras
int cuentacifras(int num){
    int i=1, cont=0;
    if(num<0) num=num-1;

    while(i<=num)
    {
        i=i+10;
        cont++;
    }
    return cont;
}
//sprimos
bool primo (int num)
{
    bool esPrimo=true;
    int i=2;
    while(i<=num/2 && esPrimo){
        if(num%i==0)
            esPrimo=false;
        i++;
    }
    return esPrimo;

}
//sumaprima
int sumaprimos(int n)
{
    int i=1, sum=0, cont=1;
    while(i<=n){
        cont++;
        if(primo(cont))
        {
            sum+=cont;
            i++;
        }
    }
    return sum;
}
//sumaprimosrecursiva
int sumaprimosrecursivo(int limite, int n)
{
    if(limite>0) {
        if (primo(n))
            return sumaprimosrecursivo(limite - 1, n + 1) + n;
        else
            return sumaprimosrecursivo(limite, n + 1);
    }
    else
        return 0;
}
//game
void adivina(int opor)
{
    srand(time(NULL));
    //numeros aleatorios entre 0 y 50:
    int num=1+(rand()%51);
    //int num=15;
    bool adivi=false;
    int n;
    cout<<endl<<"adivina el numero entre 1 y 50"<<endl;
    int i=1;
    while(i<=opor && adivi==false) {
        cout<<endl<<endl<<"OPORTUNIDAD #: "<<i;
        cout<<endl<<"ingresa tu numero: ";
        cin>>n;
        cout<<endl<<num<<endl;
        if (n > num)
            cout << endl << "El numero ingresado es mayor al que se quiere saber" <<endl;
        else if (n < num)
            cout << endl << "El numero ingresado es menor al que se quiere saber" << endl;
        else {
            cout << endl << "Felicidades" << endl;
            adivi = true;
        }
    i++;
    }
    if(adivi)
        cout<<endl<<"Eres el campeon";
    else
        cout<<endl<<"no lo lograste lo pedido ";
}
//dados
int condicion (int cant)
{
	 if (cant <= 3)
    {
    	string cad;
      cout<< "Presione \"ENTER\" para lanzar el dado 1"<<endl;
      getline(cin,cad);
	}
     else
    {
    	string cad;
      cout<< "Presione \"ENTER\" para lanzar el dado 2"<<endl;
      getline(cin,cad);
    }
		
    cin.ignore ();
}
int tirardado ()
{
  int numdados;
  srand (time (0));
  numdados = rand () % 6 + 1;
  return numdados;
}
int dado (int pdado, int sdado)
{
	if(pdado==sdado or pdado+sdado==11){
		cout << "Usted a ganado ya que saco dados iguales "<<pdado<<" : "<<sdado<<" o saco 11 en la suma de dados " << pdado + sdado<<endl;
		for (int x=1;x<=pdado;x++)
		{
			cout<<"*";
		}
		cout<<endl;
			for (int y=1;y<=sdado;y++)
		{
			cout<<"*";
		}
		
	}else{
		cout << "Usted a perido ya que no son iguales "<<pdado<<" : "<<sdado<<" o no da de la suma de los dados 11 ya que su suma es "<<pdado + sdado<<endl;
			for (int x=1;x<=pdado;x++)
		{
			cout<<"*";
		}
		cout<<endl;
					for (int y=1;y<=sdado;y++)
		{
			cout<<"*";
		}
		
	}
  
  return pdado + sdado;

}

int main() {
    int num=-90;
    cout<<endl<<"el numero "<<num<<" tiene "<<cuentacifras(num)<<" cifras";
    cout<<endl;
    //numeros primos
    num=11;
    if(primo(num))
        cout<<num<<" Es primo";
    else
        cout<<num<<" no es primo";
    cout<<endl;
    cout<<"La suma de los 4 primeros primos es: (2+3+5+7+11) "<<sumaprimos(5);
    cout<<endl;
    cout<<"La suma recursiva de los 4 primeros primos es: (2+3+5+7+11) "<<sumaprimosrecursivo(5,2);
    srand(time(NULL));
    num=rand()%51;
    cout<<endl<<"aleatorio "<<num;
    //juego de numeros
        int opcion;
    bool salir=false;
    while (true)
	{
	      cout<<endl<<"1: Nueva Oportunidad"<<endl;
          cout<<"2: Salir"<<endl;
                 cin>>opcion;
      switch (opcion)
	   {
        case 1:
                	adivina(5);
                 break;
         case 2:
                   salir=true;
              	break;
        default:
                 cout<<endl<<"opcion no valida";
       }
	      if(salir)
            break;	
	}
	   //dados (tarea)
	        bool salir2=false;
     while (true)
	{
	            cout<<endl<<"1: Tirar los dados"<<endl;
                 cout<<"2: Salir"<<endl;
                 cin>>opcion;
                  switch (opcion){
                 case 1:
	                int condicionfinal, dado1, dado2;
                    condicion (3);
                    dado1 = tirardado ();
                    condicion (4);
                    dado2 = tirardado ();
                    condicionfinal = dado(dado1, dado2);
                 break;
                case 2:
                  salir2=true;
	               break;
                  default:
                    cout<<endl<<"opcion no valida";
	            }	
	              if(salir2)
                    break;
	}
    return 0;
}
