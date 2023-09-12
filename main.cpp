#include <iostream>
using namespace std;

const int TAM=100;

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    int Sueldo;
    string ReportaA;

public:
    Empleado() {}
    Empleado(int ClvEmp,string N,string D, int S, string RptA): ClaveEmpleado(ClvEmp), Nombre(N),Domicilio(D),Sueldo(S),ReportaA(RptA) {}

    void Imprime()
    {
        cout<<"Clave de Empleado: "<<ClaveEmpleado<<endl;
        cout<<"Nombre: "<<Nombre<<endl;
        cout<<"Domicilio: "<<Domicilio<<endl;
        cout<<"Sueldo: "<<Sueldo<<endl;
        cout<<"Reporta ante: "<<ReportaA<<endl;
    }
    void CambiaDomic(string NuevoDom)
    {
        Domicilio = NuevoDom;
    }
    void CambiaReportaA(string NueRpt)
    {
        ReportaA = NueRpt;
    }
    void ActualizarSueldo(int NueSld)
    {
        Sueldo = NueSld;
    }
    void CambiarClave(int NuevaClave)
    {
        ClaveEmpleado = NuevaClave;
    }


    // ==
    bool operator ==(Empleado& e1)
    {
        return (ClaveEmpleado==e1.ClaveEmpleado);
    }




    // <<  Va estar dentro de Imprime
    friend ostream& operator <<(ostream& o, Empleado& E)
    {
        o<<"\nClave: "<<E.ClaveEmpleado;
        o<<"\nNombre: "<<E.Nombre;
        o<<"\nDomicilio: "<<E.Domicilio;
        o<<"\nSueldo: "<<E.Sueldo;
        o<<"\nSe reporta ante: "<<E.ReportaA;
        cout<<endl;
        return o;

    }


    // >>, Va a estar dentro de cambia
    friend istream& operator >>(istream& a,Empleado& e)
    {
        cout<<"Ingrese  Clave: ";
        a>>e.ClaveEmpleado;
        cout<<"Ingrese Nombre: ";
        a>>e.Nombre;
        cout<<"Ingrese Sueldo: ";
        a>>e.Sueldo;
        cout<<"Ingrese  Domicilio: ";
        a>>e.Domicilio;
        cout<<"Ingrese  Reporta a: ";
        a>>e.ReportaA;
        cout<<endl;

        return a;
    }

    //  + ocupa friend porque manipula los datos privados
    friend Empleado operator + (Empleado& E1, Empleado& E2)
    {
        return Empleado(0, "", "", E1.Sueldo + E2.Sueldo, "");

    }


    friend bool operator<(const Empleado& em1, const Empleado& em2)
    {
        return (em1.Sueldo < em2.Sueldo);
    }

    friend bool operator>(const Empleado& em1, const Empleado& em2)
    {
        return (em1.Sueldo > em2.Sueldo);
    }

    friend bool operator!=(const Empleado& em1, const Empleado& em2)
    {
        return (em1.Nombre != em2.Nombre);
    }


};


class Lista
{
private:
    Empleado datos[TAM];
    int ult;
public:
    Lista():ult(-1) {}



    bool llena()const
    {
        if(ult==TAM-1)
            return true;
        return false;
    }
    int inserta(Empleado elem, int pos)
    {
        if(llena()|| pos<0 || pos>ult+1)
        {
            std::cout<<"\n Error de insercion";
            return 0;
        }

        int i=ult+1;
        while(i>pos)
        {
            datos[i]=datos[i-1];
            i--;
        }
        datos[pos]=elem;
        ult++;
        return 1;
    }

    bool vacia()const
    {
        if(ult==-1)
            return true;
        return false;
    }
    int Agrega(Empleado elem)
    {
        if(!llena())
        {
            datos[ult+1]=elem;
            ult++;
        }
        else
        {
            cout<<"\nLista llena\n";

        }

    }

    //Va a buscar por Clave
    int Busca(Empleado elemBusc)
    {
        if(vacia())
        {
            for(int i =0; i<=ult; i++)
            {
                if(datos[i] == elemBusc)
                {
                    return i;
                }

            }
                    cout<<"Elemento no localizado\n";



        }
        return -1;
    }






    bool elimina(int pos)
    {
        if(vacia() || pos>=0 || pos>ult)
        {
            std::cout<<"\n error de eliminacion";
            return true;
        }
        int i=pos;
        while(i<ult)
        {
            datos[i]=datos[i+1];
            i++;
        }
        ult--;
        return false;
    }

    int ultimo()const
    {
        return ult;
    }

    friend std::ostream& operator<<(std::ostream & o, Lista& L)
    {
        int i=0;
        std::cout<<"\n";
        while(i<=L.ultimo())
        {
            ;
            o<<L.datos[i];
            i++;
        }
        return o;
    }




};

int main()
{

    Lista MiLista;





    Empleado x;
    int opc=0;
    int pos=0, pos1=0, posEliminar;


    do
    {
        cout<<"\nElige una opcion\n";
        cout<<"1.Agrega\n";
        cout<<"2.Buscar\n";
        cout<<"3.Elimina\n";
        cout<<"4.Inserta\n";
        cout<<"5.Muestra\n";
        cout<<"6.Salir\n";
        cin>>opc;
        switch(opc)
        {
        case 1:

            cin>>x;
            MiLista.Agrega(x);
            break;
        case 2:
            cout<<"Ingresa los datos del empleado\n";
            cin>>x;
            pos = MiLista.Busca(x);
            if(pos != 0)
            {
                cout << "Elemento encontrado posicion: "<<pos+1;
            }
            else
            {
                cout<<"Elemento no localizado";
            }

            break;
        case 3:
            cout<<"Ingresa al empleado\n";
            cin>>x;
            posEliminar = MiLista.Busca(x);
            MiLista.elimina(posEliminar);
            break;

        case 4:
            cout<<"Ingresa los datos \n";
            cin>>x;
            cout<<"Ingresa la posicion \n";
            cin>>pos1;
            MiLista.inserta(x,pos1);


            break;
        case 5:
            cout<<MiLista;

            break;




        }
    }
    while(opc !=6);









    return 0;
}
