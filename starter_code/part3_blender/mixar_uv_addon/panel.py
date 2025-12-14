import bpy

class MIXAR_PT_panel(bpy.types.Panel):
    bl_label = "Mixar UV"
    bl_space_type = "VIEW_3D"
    bl_region_type = "UI"
    bl_category = "Mixar"

    def draw(self, context):
        self.layout.operator("mixar.unwrap")
