#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera
{
public:
    Camera(Vector3 <int>);
    Camera(Camera &&) = default;
    Camera(const Camera &) = default;
    Camera &operator=(Camera &&) = default;
    Camera &operator=(const Camera &) = default;
    ~Camera();

    Camera cam;
    
private:
};

Camera::Camera()
{
}

Camera::~Camera()
{
}


#endif // !Camera_HPP