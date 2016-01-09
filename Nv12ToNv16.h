//
//  Nv12ToNv16.h
//  Nv12ToNv16
//
//  Created by Hank Lee on 7/31/15.
//  Copyright (c) 2015 Hank Lee. All rights reserved.
//

#ifndef __Nv12ToNv16__
#define __Nv12ToNv16__


extern int expand
(
  const uint32_t width,
  const uint32_t height,
        uint16_t u_et_v_dst[height    ][width / 2],
  const uint16_t u_et_v_src[height / 2][width / 2]
);


#endif
