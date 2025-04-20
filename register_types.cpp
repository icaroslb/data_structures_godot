#include "register_types.h"

#include "core/object/class_db.h"

#include "SetGodot/SetOperations.h"
#include "StackGodot/Stack.h"
#include "QueueGodot/Queue.h"
#include "LinkedListGodot/LinkedList.h"

void initialize_data_structures_godot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<Set>();
	ClassDB::register_class<SetIterator>();	
	ClassDB::register_class<SetrIterator>();	
	ClassDB::register_class<SetOperations>();
	ClassDB::register_class<Stack>();
	ClassDB::register_class<Queue>();
	ClassDB::register_class<LinkedList>();
	ClassDB::register_class<LinkedListIterator>();
	ClassDB::register_class<LinkedListrIterator>();
}

void uninitialize_data_structures_godot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
   // Nothing to do here in this example.
}