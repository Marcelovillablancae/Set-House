#include <iostream>
#include <string>

using namespace std;

class Ambiente{
public:
    Ambiente(){
        Bstatus=false;
    }
    virtual ~Ambiente(){

    }

    void virtual setStatus(){
        Bstatus= !(Bstatus);
    }
    bool getStatus(){
        return Bstatus;
    }

protected:
    bool Bstatus;
};

class Descanso : public Ambiente{
public:
    Descanso(){
        ILightLevel=50;
        BLightstate=false;
    }
    void TurnLight(){
        BLightstate= !BLightstate;
    }
    void IncreaseLevel(){
        if (ILightLevel<=90){
            ILightLevel+=10;
        }
        if(ILightLevel>=100) ILightLevel = 100;
    }
    void DecreaseLevel(){
        if (ILightLevel<=10){
            ILightLevel+=10;
        }
        if(ILightLevel>=0) ILightLevel = 0;
    }
    void setStatus(){
        Bstatus= !Bstatus;
        if(Bstatus==true){
            BLightstate=true;
            ILightLevel=50;
        }
    }

private:
    int ILightLevel;
    bool BLightstate;
};

class Dormir : public Ambiente{
public:
    Dormir(){
    }
    ~Dormir(){
    }

    //Por Hacer
private:
    //Por Hacer
};

class Seguridad : public Ambiente{
public:
    Seguridad(){
    }
    ~Seguridad(){
    }
    //Por Hacer
private:
    //Por Hacer
};


class Usuario{
public:
    Usuario(){
        Iedad=0;
        Snombre="";
        Susuario="";
        Scontrasena="";
        Snumero="";
    }
    Usuario(int Fedad,string Fnombre,string Fusuario,string Fcontrasena,string Fnumero){
        Iedad=Fedad;
        Snombre=Fnombre;
        Susuario=Fusuario;
        Scontrasena=Fcontrasena;
        Snumero=Fnumero;
    }
    ~Usuario(){
        delete descanso;
        delete dormir;
        delete seguridad;
    }
    void setEdad(int Fedad){
        Iedad=Fedad;
    }
    void setNombre(string Fnombre){
         Susuario=Fnombre;
    }
    void setUsuario(string Fusuario){
         Susuario=Fusuario;
    }
    void setContrasena(string Fcontrasena){
         Susuario=Fcontrasena;
    }
    void TurnDescanso(){
        descanso->setStatus();
    }
    void TurnDormir(){
        dormir->setStatus();
    }
    void TurnSeguridad(){
        seguridad->setStatus();
    }
    string getName(){
        return Snombre;
    }
    int getEdad(){
        return Iedad;
    }
    bool statusDescanso(){
        return descanso->getStatus();
    }
    bool statusDormir(){
        return dormir->getStatus();
    }
    bool statusSeguridad(){
        return seguridad->getStatus();
    }

protected:
    int Iedad;
    string Snombre;
    string Susuario;
    string Scontrasena;
    string Snumero;
    Ambiente *descanso = new Descanso;
    Ambiente *dormir = new Dormir;
    Ambiente *seguridad = new Seguridad;
};


int main()
{
    Usuario *Marcelo= new Usuario(19,"Marcelo","Marcelox","TuPoto#123#","+56911111111");
    Marcelo->TurnDescanso();
    cout << Marcelo->getName() << " Tiene " << Marcelo->getEdad() << " años." << endl;
    if(Marcelo->statusDescanso() == true) cout << "Esta descansando" << endl;
    else cout <<"No esta descansando" << endl;
    if(Marcelo->statusDormir() == true) cout << "Esta durmiendo" << endl;
    else cout <<"No esta durmiendo" << endl;
    if(Marcelo->statusSeguridad() == true) cout << "No esta en la casa" << endl;
    else cout <<"Esta en la casa" << endl;
    return 0;
}
