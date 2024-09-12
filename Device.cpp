#include<iostream>
#include<vector>
#include<math.h>


class shape
{
    public:
    shape(float _X = 0 , float _Y = 0, float _Z = 0 , float _density = 1)
    {
        A = _X;
        B = _Y;
        C = _Z;
        density = _density;
    }

   

    float EvalSurfaceArea()
    {
        _SurfaceArea =  2*(A*B + B*C + A*C);
        return _SurfaceArea;
    }

    float EvalMass()
    {
        _Mass = _Volume * density;
        return _Mass;
    }

     float EvalVolume()
    {
        _Volume = A*B*C;
        return  _Volume;
    }

    private:
    float   _SurfaceArea ,_Volume,_Mass,A, B, C, density;
};


class cylinder 
{
    public:
    cylinder (float _height = 0 , float _radius = 0 ,float _density = 1)
    {
        height = _height;
        radius = _radius;
        density = _density;
    }
    

    float EvalSurfaceArea ()
    {
        _SurfaceArea = (4.0 * 3.14 * radius) + (2.0 * 3.14 * radius * height);
        return _SurfaceArea;
    }


    float EvalMass()
    {
        _Mass = _volume * density;
        return _Mass;
    }

     float EvalVolume ()
    {
           _volume = (3.14 * radius * radius * height);
           return _volume;
    }

    private:
    float density , height , radius , _volume , _SurfaceArea ,  _Mass;
};


class sphere
{
    public:
    sphere(float _radius = 0 , float _density = 1)
    {
       radius =  _radius;
       density = _density;
    }

   

    float EvalSurfaceArea() 
    { 
        _SurfaceArea = 4 * 3.14 * radius * radius; 
        return _SurfaceArea;
    }

    float EvalMass()
    {
        _Mass = _volume * density;
        return _Mass;
    }
    float EvalVolume()
    {
        _volume = (4.0 / 3.0) * 3.14 * radius * radius * radius;
        return _volume;
    }

    private:
    float radius,density , _volume , _SurfaceArea ,  _Mass;

} ;




    class Device
{
    public:

    Device(std::string name = "defaultname")
    {   
        DeviceName = name;
    }

    void add_complicatedpart (Device device)
    {
        child_vec.push_back(&device);
    }


     void add_simplepart (shape shape)
    {
        shape_vec.push_back(&shape);
    }


 float CalcSurfaceArea()
    {
        float tmp = 0;
        for(int i = 0 ; i < shape_vec.size() ; i++ )
        {
           tmp = tmp + (*shape_vec[i]).EvalSurfaceArea();
        }
        for(int i = 0 ; i < child_vec.size() ; i++)
        {
            tmp = tmp + (*child_vec[i]).CalcSurfaceArea();
        }
        return tmp;
    }



    float CalcVolume()
    {
      float tmp = 0;
        for(int i = 0 ; i < shape_vec.size() ; i++ )
        {
           tmp = tmp + (*shape_vec[i]).EvalVolume();
        }
        for(int i = 0 ; i < child_vec.size() ; i++)
        {
            tmp = tmp + (*child_vec[i]).CalcVolume();
        }
        return tmp;
        
    }

   

    float CalcMass()
    {
        float tmp = 0;
        for(int i = 0 ; i < shape_vec.size() ; i++ )
        {
           tmp = tmp + (*shape_vec[i]).EvalMass();
        }
        for(int i = 0 ; i < child_vec.size() ; i++)
        {
            tmp = tmp + (*child_vec[i]).CalcMass();
        }
        return tmp;
    }
    
    private:
    std::vector<Device*>child_vec;
    std::vector<shape*>shape_vec;
    std::string DeviceName;
};



int main()
{
    Device MAinDevice;
    shape simplepart1(21, 1, 2, 10);
    Device Comppart1;
     shape simplepart2(1, 2, 1, 2);
    Device Comppart2;
     shape simplepart3(4, 2, 2, 1);
    Device Comppart3;
   
   
   
    //add comp parts
    MAinDevice.add_complicatedpart(Comppart1);

    MAinDevice.add_complicatedpart(Comppart2);

    MAinDevice.add_complicatedpart(Comppart3);

    //add simple part
    MAinDevice.add_simplepart(simplepart1);

    MAinDevice.add_simplepart(simplepart2);

    MAinDevice.add_simplepart(simplepart3);

    //printing volume and surface and mass

    std::cout << MAinDevice.CalcVolume() << std::endl;

    std::cout << MAinDevice.CalcSurfaceArea() << std::endl;
    
    std::cout << MAinDevice.CalcMass() << std::endl;
}