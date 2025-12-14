bl_info = {
    "name": "Mixar UV Unwrap",
    "blender": (4, 2, 0),
    "category": "UV"
}

from .operators import *
from .panel import *

def register():
    bpy.utils.register_class(MIXAR_OT_unwrap)
    bpy.utils.register_class(MIXAR_PT_panel)

def unregister():
    bpy.utils.unregister_class(MIXAR_OT_unwrap)
    bpy.utils.unregister_class(MIXAR_PT_panel)
