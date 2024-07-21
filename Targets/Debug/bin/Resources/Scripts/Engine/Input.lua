-- define module table
local ChainSawInput = {}

-- check mouse input
function ChainSawInput.IsMouse(button)
    return ApiMouseDown(button)
end

-- check key input
function ChainSawInput.IsKey(key)
    return ApiKeyDown(key)
end

-- mouse input codes
ChainSawInput.MOUSE_LEFT        = 0
ChainSawInput.MOUSE_MIDDLE      = 1
ChainSawInput.MOUSE_RIGHT       = 2
ChainSawInput.MOUSE_BUTTON_4    = 3
ChainSawInput.MOUSE_BUTTON_5    = 4
ChainSawInput.MOUSE_BUTTON_6    = 5
ChainSawInput.MOUSE_BUTTON_7    = 6
ChainSawInput.MOUSE_BUTTON_8    = 7

-- key input codes
ChainSawInput.KEY_SPACE         = 32
ChainSawInput.KEY_APOSTROPHE    = 39
ChainSawInput.KEY_COMMA         = 44
ChainSawInput.KEY_MINUS         = 45
ChainSawInput.KEY_PERIOD        = 46
ChainSawInput.KEY_SLASH         = 47
ChainSawInput.KEY_0             = 48
ChainSawInput.KEY_1             = 49
ChainSawInput.KEY_2             = 50
ChainSawInput.KEY_3             = 51
ChainSawInput.KEY_4             = 52
ChainSawInput.KEY_5             = 53
ChainSawInput.KEY_6             = 54
ChainSawInput.KEY_7             = 55
ChainSawInput.KEY_8             = 56
ChainSawInput.KEY_9             = 57
ChainSawInput.KEY_SEMICOLON     = 59
ChainSawInput.KEY_EQUAL         = 61
ChainSawInput.KEY_A             = 65
ChainSawInput.KEY_B             = 66
ChainSawInput.KEY_C             = 67
ChainSawInput.KEY_D             = 68
ChainSawInput.KEY_E             = 69
ChainSawInput.KEY_F             = 70
ChainSawInput.KEY_G             = 71
ChainSawInput.KEY_H             = 72
ChainSawInput.KEY_I             = 73
ChainSawInput.KEY_J             = 74
ChainSawInput.KEY_K             = 75
ChainSawInput.KEY_L             = 76
ChainSawInput.KEY_M             = 77
ChainSawInput.KEY_N             = 78
ChainSawInput.KEY_O             = 79
ChainSawInput.KEY_P             = 80
ChainSawInput.KEY_Q             = 81
ChainSawInput.KEY_R             = 82
ChainSawInput.KEY_S             = 83
ChainSawInput.KEY_T             = 84
ChainSawInput.KEY_U             = 85
ChainSawInput.KEY_V             = 86
ChainSawInput.KEY_W             = 87
ChainSawInput.KEY_X             = 88
ChainSawInput.KEY_Y             = 89
ChainSawInput.KEY_Z             = 90
ChainSawInput.KEY_LEFT_BRACKET  = 91
ChainSawInput.KEY_BACKSLASH     = 92
ChainSawInput.KEY_RIGHT_BRACKET = 93
ChainSawInput.KEY_GRAVE_ACCENT  = 96
ChainSawInput.KEY_WORLD_1       = 161
ChainSawInput.KEY_WORLD_2       = 162

-- Fion keys *--
ChainSawInput.KEY_ESCAPE        = 256
ChainSawInput.KEY_ENTER         = 257
ChainSawInput.KEY_TAB           = 258
ChainSawInput.KEY_BACKSPACE     = 259
ChainSawInput.KEY_INSERT        = 260
ChainSawInput.KEY_DELETE        = 261
ChainSawInput.KEY_RIGHT         = 262
ChainSawInput.KEY_LEFT          = 263
ChainSawInput.KEY_DOWN          = 264
ChainSawInput.KEY_UP            = 265
ChainSawInput.KEY_PAGE_UP       = 266
ChainSawInput.KEY_PAGE_DOWN     = 267
ChainSawInput.KEY_HOME          = 268
ChainSawInput.KEY_END           = 269
ChainSawInput.KEY_CAPS_LOCK     = 280
ChainSawInput.KEY_SCROLL_LOCK   = 281
ChainSawInput.KEY_NUM_LOCK      = 282
ChainSawInput.KEY_PRINT_SCREEN  = 283
ChainSawInput.KEY_PAUSE         = 284
ChainSawInput.KEY_F1            = 290
ChainSawInput.KEY_F2            = 291
ChainSawInput.KEY_F3            = 292
ChainSawInput.KEY_F4            = 293
ChainSawInput.KEY_F5            = 294
ChainSawInput.KEY_F6            = 295
ChainSawInput.KEY_F7            = 296
ChainSawInput.KEY_F8            = 297
ChainSawInput.KEY_F9            = 298
ChainSawInput.KEY_F10           = 299
ChainSawInput.KEY_F11           = 300
ChainSawInput.KEY_F12           = 301
ChainSawInput.KEY_F13           = 302
ChainSawInput.KEY_F14           = 303
ChainSawInput.KEY_F15           = 304
ChainSawInput.KEY_F16           = 305
ChainSawInput.KEY_F17           = 306
ChainSawInput.KEY_F18           = 307
ChainSawInput.KEY_F19           = 308
ChainSawInput.KEY_F20           = 309
ChainSawInput.KEY_F21           = 310
ChainSawInput.KEY_F22           = 311
ChainSawInput.KEY_F23           = 312
ChainSawInput.KEY_F24           = 313
ChainSawInput.KEY_F25           = 314
ChainSawInput.KEY_KP_0          = 320
ChainSawInput.KEY_KP_1          = 321
ChainSawInput.KEY_KP_2          = 322
ChainSawInput.KEY_KP_3          = 323
ChainSawInput.KEY_KP_4          = 324
ChainSawInput.KEY_KP_5          = 325
ChainSawInput.KEY_KP_6          = 326
ChainSawInput.KEY_KP_7          = 327
ChainSawInput.KEY_KP_8          = 328
ChainSawInput.KEY_KP_9          = 329
ChainSawInput.KEY_KP_DECIMAL    = 330
ChainSawInput.KEY_KP_DIVIDE     = 331
ChainSawInput.KEY_KP_MULTIPLY   = 332
ChainSawInput.KEY_KP_SUBTRACT   = 333
ChainSawInput.KEY_KP_ADD        = 334
ChainSawInput.KEY_KP_ENTER      = 335
ChainSawInput.KEY_KP_EQUAL      = 336
ChainSawInput.KEY_LEFT_SHIFT    = 340
ChainSawInput.KEY_LEFT_CONTROL  = 341
ChainSawInput.KEY_LEFT_ALT      = 342
ChainSawInput.KEY_LEFT_SUPER    = 343
ChainSawInput.KEY_RIGHT_SHIFT   = 344
ChainSawInput.KEY_RIGHT_CONTROL = 345
ChainSawInput.KEY_RIGHT_ALT     = 346
ChainSawInput.KEY_RIGHT_SUPER   = 347
ChainSawInput.KEY_MENU          = 348

-- export module
return ChainSawInput
