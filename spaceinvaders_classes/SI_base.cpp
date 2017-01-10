#include "SI_base.h"

//define constructor
SI_base::SI_base(signed int x, signed int y){
    this->SetX(x);
    this->SetY(y);
};

//define destructor
SI_base::~SI_base(){
    cout<<"SI_base destroyed"<<endl;
};
