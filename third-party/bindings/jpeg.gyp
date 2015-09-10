{
    "includes": ["./common.gyp"],
    "targets": [
        {
            "target_name": "jpeg",
            "type": "static_library",
            "include_dirs": [
                "../jpeg"
            ],
            "sources": [
                "../jpeg/ansi2knr.c",
                "../jpeg/cdjpeg.c",
                "../jpeg/cjpeg.c",
                "../jpeg/ckconfig.c",
                "../jpeg/djpeg.c",
                "../jpeg/example.c",
                "../jpeg/jcapimin.c",
                "../jpeg/jcapistd.c",
                "../jpeg/jccoefct.c",
                "../jpeg/jccolor.c",
                "../jpeg/jcdctmgr.c",
                "../jpeg/jchuff.c",
                "../jpeg/jcinit.c",
                "../jpeg/jcmainct.c",
                "../jpeg/jcmarker.c",
                "../jpeg/jcmaster.c",
                "../jpeg/jcomapi.c",
                "../jpeg/jcparam.c",
                "../jpeg/jcphuff.c",
                "../jpeg/jcprepct.c",
                "../jpeg/jcsample.c",
                "../jpeg/jctrans.c",
                "../jpeg/jdapimin.c",
                "../jpeg/jdapistd.c",
                "../jpeg/jdatadst.c",
                "../jpeg/jdatasrc.c",
                "../jpeg/jdcoefct.c",
                "../jpeg/jdcolor.c",
                "../jpeg/jddctmgr.c",
                "../jpeg/jdhuff.c",
                "../jpeg/jdinput.c",
                "../jpeg/jdmainct.c",
                "../jpeg/jdmarker.c",
                "../jpeg/jdmaster.c",
                "../jpeg/jdmerge.c",
                "../jpeg/jdphuff.c",
                "../jpeg/jdpostct.c",
                "../jpeg/jdsample.c",
                "../jpeg/jdtrans.c",
                "../jpeg/jerror.c",
                "../jpeg/jfdctflt.c",
                "../jpeg/jfdctfst.c",
                "../jpeg/jfdctint.c",
                "../jpeg/jidctflt.c",
                "../jpeg/jidctfst.c",
                "../jpeg/jidctint.c",
                "../jpeg/jidctred.c",
                "../jpeg/jmemansi.c",
                # "../jpeg/jmemdos.c",
                # "../jpeg/jmemmac.c",
                "../jpeg/jmemmgr.c",
                "../jpeg/jmemname.c",
                "../jpeg/jmemnobs.c",
                "../jpeg/jpegtran.c",
                "../jpeg/jquant1.c",
                "../jpeg/jquant2.c",
                "../jpeg/jutils.c",
                "../jpeg/rdbmp.c",
                "../jpeg/rdcolmap.c",
                "../jpeg/rdgif.c",
                "../jpeg/rdjpgcom.c",
                "../jpeg/rdppm.c",
                "../jpeg/rdrle.c",
                "../jpeg/rdswitch.c",
                "../jpeg/rdtarga.c",
                "../jpeg/transupp.c",
                "../jpeg/wrbmp.c",
                "../jpeg/wrgif.c",
                "../jpeg/wrjpgcom.c",
                "../jpeg/wrppm.c",
                "../jpeg/wrrle.c",
                "../jpeg/wrtarga.c"
            ],
            "conditions": [
                [
                    "OS==\"linux\"",
                    {
                        "include_dirs": [
                            "platform-includes/linux/jpeg"
                        ]
                    }
                ],
                [
                    "OS==\"mac\"",
                    {
                        "defines": [
                           # "USE_MAC_MEMMGR"
                        ],
                        "include_dirs": [
                            "platform-includes/mac/jpeg"
                        ],
                        "sources" : [
                            # "../jpeg/jmemmac.c"
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
                            "platform-includes/win/jpeg"
                        ],
                        "sources" : [
                            "../jpeg/jmemdos.c"
                        ]
                    }
                ]
            ]
        }
    ]
}