#ifndef CAMERA_H
#define CAMERA_H

#include "graphics_headers.h"

class Camera
{
public:
    Camera();
    ~Camera();
    bool Initialize(int w, int h);
    glm::mat4 GetProjection();
    glm::mat4 GetView();

    void UpdatePosition(bool forward, bool backward, bool left, bool right, bool goUp, bool goDown, float deltaTime);



private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 back;
    glm::vec3 up;


    glm::mat4 projection;
    glm::mat4 view;

    float pitch;
    float camSpeed;


};

#endif /* CAMERA_H */
