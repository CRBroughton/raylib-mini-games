#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"
#include <math.h>
#include <vector>

/**
 * Calculates the Euclidean distance between two 3D vectors (points).
 *
 * @param v1 The first 3D vector.
 * @param v2 The second 3D vector.
 * @return The scalar distance between v1 and v2.
 */
inline float Vector3Distance(Vector3 v1, Vector3 v2)
{
    return sqrtf((v2.x - v1.x) * (v2.x - v1.x) +
                 (v2.y - v1.y) * (v2.y - v1.y) +
                 (v2.z - v1.z) * (v2.z - v1.z));
}

/**
 * Normalizes a 3D vector to have a length (magnitude) of 1.
 *
 * @param v The input 3D vector to normalize.
 * @return A normalized version of the vector v.
 */
inline Vector3 Vector3Normalize(Vector3 v)
{
    float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (length != 0.0f)
    {
        float invLength = 1.0f / length;
        v.x *= invLength;
        v.y *= invLength;
        v.z *= invLength;
    }
    return v;
}

/**
 * Subtracts one 3D vector from another.
 *
 * @param v1 The first 3D vector (minuend).
 * @param v2 The second 3D vector (subtrahend).
 * @return The result of subtracting v2 from v1 as a new 3D vector.
 */
inline Vector3 Vector3Subtract(Vector3 v1, Vector3 v2)
{
    return (Vector3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

/**
 * Draws a thick 3D line between two points in space.
 *
 * @param start The starting point of the line.
 * @param end The ending point of the line.
 * @param thickness The thickness (radius) of the line.
 * @param colour The colour of the line.
 *
 * This function approximates a thick 3D line by drawing a cylinder between
 * the two given points. The cylinder is oriented along the direction of the line
 * and its radius is defined by the thickness parameter.
 */
inline void DrawThickLine3D(Vector3 start, Vector3 end, float thickness, Color colour)
{
    // Draw a cylinder between the two points to simulate a thicker line
    DrawCylinderEx(start, end, thickness, thickness, 8, colour);
}

/**
 * Updates the camera position to rotate around a specified center point.
 *
 * @param camera Pointer to the Camera3D object to update.
 * @param center The center point around which the camera should rotate.
 * @param radius The distance of the camera from the center.
 * @param rotationSpeed The speed at which the camera rotates around the center.
 */
inline void UpdateCameraRelativeToCenter(Camera3D *camera, const Vector3 center, float radius, float rotationSpeed)
{
    float angle = GetTime() * rotationSpeed;

    camera->position.x = center.x + cosf(angle) * radius;
    camera->position.y = center.y;
    camera->position.z = center.z + sinf(angle) * radius;

    camera->target = center;
}
#endif // UTILS_H
