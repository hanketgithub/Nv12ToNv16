//
//  Nv12ToNv16.c
//  Nv12ToNv16
//
//  Created by Hank Lee on 7/31/15.
//  Copyright (c) 2015 Hank Lee. All rights reserved.
//

#include <stdint.h>

int expand
(
  const uint32_t width,
  const uint32_t height,
        uint16_t u_et_v_dst[height    ][width / 2],
  const uint16_t u_et_v_src[height / 2][width / 2]
)
{
    int i, j;
    
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width / 2; i++)
        {            
            // Duplicate sample
            u_et_v_dst[j][i] = u_et_v_src[j / 2][i];
        }
    }

    return 0;
}
