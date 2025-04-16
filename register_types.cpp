#include "register_types.h"

#include "core/object/class_db.h"

#include "SetGodot/SetOperations.h"
#include "StackGodot/Stack.h"
#include "QueueGodot/Queue.h"

void initialize_data_structures_godot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<Set>();
	ClassDB::register_class<SetIterator>();	
	ClassDB::register_class<SetOperations>();
	ClassDB::register_class<Stack>();
	ClassDB::register_class<Queue>();
}

void uninitialize_data_structures_godot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
   // Nothing to do here in this example.
}