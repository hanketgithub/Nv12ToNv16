//
//  main.c
//  Nv12ToNv16
//
//  Created by Hank Lee on 7/31/15.
//  Copyright (c) 2015 Hank Lee. All rights reserved.
//
//  Given NV 12, produce NV 16
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "Nv12ToNv16.h"

int main(int argc, char *argv[])
{
    int fd_in;
    int fd_out;
    
    uint32_t rd_sz;
    
    uint32_t width;
    uint32_t height;
    uint32_t frame_size;
    
    char *output_file_name;
    
    uint8_t *frame;
    
    
    if (argc < 4)
    {
        printf("usage: %s [input yuv] [width] [height]\n", argv[0]);
        return -1;
    }
    
    
    output_file_name = "nv16.yuv";
    
    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(output_file_name, O_WRONLY | O_CREAT, S_IRUSR);
    
    width = atoi(argv[2]);
    height = atoi(argv[3]);
    
    frame_size = width * height;
    
    
    const uint8_t  (*y_src)     [width];
    const uint16_t (*u_et_v_src)[width / 2];
    uint16_t (*u_et_v_dst)[width / 2];
    
    frame = malloc(frame_size * 3 / 2);
    u_et_v_dst = malloc(frame_size);
    
    y_src = (const uint8_t (*)[width]) frame;
    u_et_v_src = (const uint16_t (*)[width]) (y_src + height);
    
    printf("Processing: ");
    
    while (1)
    {
        rd_sz = read(fd_in, frame, frame_size * 3 / 2);
        
        if (rd_sz == frame_size * 3 / 2)
        {
            expand
            (
             width,
             height,
             u_et_v_dst,
             u_et_v_src
             );
            
            write(fd_out, y_src,     frame_size);
            write(fd_out, u_et_v_dst, frame_size);
        }
        else
        {
            break;
        }
        
        fputc('.', stdout);
        fflush(stdout);
    }
    
    printf("Done\n");
    printf("Output file: %s\n", output_file_name);
    
    return 0;
}

