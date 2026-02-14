#include <iostream>
#include <vector>

class Phone {
    public:
        std::string MakeCall() {return "Calling..."; }
        std::string Use() { return "Calling..."; }
};

class Camera {
    public:
        std::string TakePhoto() {return "Photo taken";}
        std::string Use() { return "Photo taken"; }
};

class Smartphone : public Phone, public Camera {
};

int main() {
    Phone phone;
    Camera camera;
    Smartphone smartphone;

    std::cout << phone.MakeCall() << "\n";
    std::cout << phone.Use() << "\n";

    std::cout << camera.TakePhoto() << "\n";
    std::cout << camera.Use() << "\n";

    std::cout << smartphone.MakeCall() << "\n";
    std::cout << smartphone.TakePhoto() << "\n";
    
    //std::cout << smartphone.Use() << "\n"; //ambiguous

    std::cout << smartphone.Phone::Use() << "\n";
    std::cout << smartphone.Camera::Use() << "\n";
}
