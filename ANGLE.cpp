#include <iostream>
#include "ANGLE.h"

int ANGLE_init(ANGLE* this_a, const POINT* main_p, const POINT* first_ray_p, const POINT* second_ray_p)
{
    if (this_a == NULL || main_p == NULL || first_ray_p == NULL || second_ray_p == NULL) return 1;

    float radius = POINT_distance(main_p, first_ray_p);
    float part_of_arc = 1.17e-38;
      



    return 0;

}
