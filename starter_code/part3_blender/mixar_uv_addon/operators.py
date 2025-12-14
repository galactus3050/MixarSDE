import bpy

class MIXAR_OT_unwrap(bpy.types.Operator):
    bl_idname = "mixar.unwrap"
    bl_label = "Auto UV Unwrap"

    def execute(self, context):
        bpy.ops.uv.unwrap(method='ANGLE_BASED')
        return {'FINISHED'}
