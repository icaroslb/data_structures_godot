#include "register_types.h"

#include "core/object/class_db.h"

#include "Set/SetOperations.h"

void initialize_data_structures_godot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<Set>();
	ClassDB::register_class<SetIterator>();	
}

void uninitialize_data_structures_godot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
   // Nothing to do here in this example.
}