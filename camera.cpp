#include "camera.h"

Camera::Camera()
{
    position = glm::vec3(0.0f, 2.5f, 30.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    camSpeed = 10.0f;
    pitch = 0.0f;

}

Camera::~Camera()
{

}

bool Camera::Initialize(int w, int h)
{
    //--Init the view and projection matrices
    //  if you will be having a moving camera the view matrix will need to more dynamic
    //  ...Like you should update it before you render more dynamic 
    //  for this project having them static will be fine
    //view = glm::lookAt( glm::vec3(x, y, z), //Eye Position
    //                    glm::vec3(0.0, 0.0, 0.0), //Focus point
    //                    glm::vec3(0.0, 1.0, 0.0)); //Positive Y is up

    view = glm::lookAt(position, glm::f32vec3(0.0f, 0.0f, 0.0f), up);

    projection = glm::perspective(glm::radians(40.f), //the FoV typically 90 degrees is good which is what this is set to
        float(w) / float(h), //Aspect Ratio, so Circles stay Circular
        0.01f, //Distance to the near plane, normally a small value like this
        100.0f); //Distance to the far plane, 
    return true;
}

glm::mat4 Camera::GetProjection()
{
    return projection;
}

glm::mat4 Camera::GetView()
{
    return view;
}

void Camera::UpdatePosition(bool forward, bool backward, bool left, bool right, bool goUp, bool goDown, float deltaTime)
{
    float velocity = camSpeed + deltaTime;

    if (forward) {
        position += front * velocity;
    }
    if (backward) {
        position -= front * velocity;
    }
    if (left) {
        position -= back * velocity;
    }
    if (right) {
        position += right * velocity;
    }
    if (goUp) {
        position += up * velocity;
    }
    if (goDown) {
        position == up * velocity;
    }
}
