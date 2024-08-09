#include<iostream>
#include "shape.h"
using namespace std;


class Automobile
{
    protected:
        //simple parts
        string brand;
        string model;
        string color;
        string body_material;
        bool Automated_gearbox;

    public:
    Automobile(){}
    Automobile(string _brand , string _model)
        {
            brand = _brand;
            model = _model;
        }
        void get_brand(string _brand)
        {
            brand = _brand;
        }
        void get_model(string _model)
        {
            model = _model;
        }
        void get_color(string _color)
        {
            color = _color;
        }
        void get_body_material(string _body)
        {
            body_material = _body;
        }
        void have_Automated_gearbox(bool _driver)
        {
            Automated_gearbox = _driver;
        }
        void print_Automobile_detail()
        {
            cout << "This Automobile is of brand " << brand << " and is a model " << model << " and is made of " << color << " " << body_material << endl;
        }
};

//complicated parts of Automobile
class engine:public Automobile
{
    protected:
        //simple parts of engine
        int piston_count;
        string engin_block_material;
    public:
    engine(){}
    engine(string _brand , string _model)
    {
        brand = _brand;
        model = _model;
    }
    void get_piston_count(float count)
    {
        piston_count = count;
    }
    void get_engin_block_material(string mat)
    {
        engin_block_material = mat;
    }
    void print_engine_detail()
    {
        cout << "This engine has " << piston_count << " pistons and the engin block material is " << engin_block_material << " and is of the brand " << brand << " and is a model " << model << endl;
    }
};

class gearbox:public Automobile
{
    protected:
        //simple part of gearbox
        int gears;
        string gearbox_material;
    public:
    gearbox(){}
    gearbox(string _brand , string _model)
        {
            brand = _brand;
            model = _model;
        }
        void h_gears(int size)
        {
            gears = size;
        }
        void get_gearbox_material(string mat)
        {
            gearbox_material = mat;
        }
        void print_gearbox_detail()
        {
            cout << "The gearbox has " << gears << " gears and the gearbox material is " << gearbox_material<< " and is of the brand " << brand << " and is a model " << model << endl;
        }
};

//complicated part of engine
class cylinder:public engine
{
    protected:
        string material_c;
    public:
        void get_cylinder_material(string mat)
        {
            material_c = mat ;
        }
        void print_cylinder_details ()
        {
            cout << "The cylinder is made of " << material_c << endl;
        }

};

//complicated part of gearbox
class gearbox_bearing:public gearbox
{
protected:
    string type;
public:
    void get_gearbox_bearing( string _type)
    {
        type =  _type;
    }
    void print_gearbox_bearing_details ()
    {
        cout << "The bearing is a " << type<<endl;
    }
};


int main() {
    Automobile car ("samand" , "lx");
    car.get_color("nokmedadi");
    car.get_body_material("alominum");
    car.have_Automated_gearbox(0);
    engine car_engine ("HEV" , "sobaro");
    car_engine.get_piston_count(6);
    car_engine.get_engin_block_material("foolad");
    gearbox car_gearbox ("xu7" , "esakooyi");
    car_gearbox.h_gears(6);
    car_gearbox.get_gearbox_material("chodan");
    cylinder car_cylinder;
    car_cylinder.get_cylinder_material("aliazh");
    gearbox_bearing car_bearing;
    car_bearing.get_gearbox_bearing("papered roller bearing");
    car.print_Automobile_detail();
    car_engine.print_engine_detail();
    car_gearbox.print_gearbox_detail();
    car_cylinder.print_cylinder_details();
    car_bearing.print_gearbox_bearing_details();
    cout << endl;





    //automobile -->
    Cube automobile (2,1,1);
    automobile.set_density(5000);
    cout << "automobile"<<endl<<" volume: " << automobile.EvalVolume() << endl <<  " mass: " << automobile.EvalMass() << endl << " suface: " << automobile.EvalSurface() << endl ;
    //engine -->
    Cube my_engine (0.5 , 0.6 , 0.5);
    my_engine.set_density(1000);
    cout << "engine"<<endl<<" volume: " << my_engine.EvalVolume() << endl <<  " mass: " << my_engine.EvalMass() << endl << " suface: " << my_engine.EvalSurface() << endl ;
    //gearbox -->
    Cube my_gearbox (0.4 , 0.4 , 0.4);
    my_gearbox.set_density(6000);
    cout << "gearbox"<<endl<<" volume: " << my_gearbox.EvalVolume() << endl <<  " mass: " << my_gearbox.EvalMass() << endl << " suface: " << my_gearbox.EvalSurface()<<endl;
    //piston -->
    Cylinder my_piston (0.05 , 0.2);
    my_piston.set_density(4000);
    cout << "piston"<<endl<<" volume: " << my_piston.EvalVolume() << endl <<  " mass: " << my_piston.EvalMass() << endl << " suface: " << my_piston.EvalSurface()<<endl ;
    //cylinder -->
    Cylinder my_cylinder (0.06 , 0.1);
    my_cylinder.set_density(5000);
    cout << "cylinder"<<endl<<" volume: " << my_cylinder.EvalVolume() << endl <<  " mass: " << my_cylinder.EvalMass() << endl << " suface: " << my_cylinder.EvalSurface()<<endl;


}