{
    "includes": ["./common.gyp"],
    "targets": [
        {
            "target_name": "libpng",
            "type": "static_library",
            "include_dirs": [
                "../libpng"
            ],
            "sources": [
                "../libpng/arm/arm_init.c",
                "../libpng/arm/filter_neon_intrinsics.c",
                "../libpng/png.c",
                "../libpng/pngerror.c",
                "../libpng/pngget.c",
                "../libpng/pngmem.c",
                "../libpng/pngpread.c",
                "../libpng/pngread.c",
                "../libpng/pngrio.c",
                "../libpng/pngrtran.c",
                "../libpng/pngrutil.c",
                "../libpng/pngset.c",
                "../libpng/pngtest.c",
                "../libpng/pngtrans.c",
                "../libpng/pngwio.c",
                "../libpng/pngwrite.c",
                "../libpng/pngwtran.c",
                "../libpng/pngwutil.c"
            ],
            "conditions": [
                [
                    "OS==\"linux\"",
                    {
                        "include_dirs": [
                            "platform-includes/linux/libpng"
                        ]
                    }
                ],
                [
                    "OS==\"mac\"",
                    {
                        "include_dirs": [
                            "platform-includes/mac/libpng"
                        ]
                    }
                ],
                [
                    "OS==\"win\"",
                    {
                        "defines": [
                            "USE_MSDOS_MEMMGR"
                        ],
                        "include_dirs": [
                            "platform-includes/win/libpng"
                        ]
                    }
                ]
            ]
        }
    ]
}