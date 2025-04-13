#include "Set/SetOperations.h"

#include <algorithm>

// Set SetOperations::union_op(const Set& set_0, const Set& set_1) {
//     Set result;

//     std::for_each(std::begin(set_0), std::end(set_0), [&] (const Variant& value) {
//         result.insert(value);
//     });

//     std::for_each(std::begin(set_1), std::end(set_1), [&] (const Variant& value) {
//         result.insert(value);
//     });

//     return result;
// }

// Set SetOperations::intersection_op(const Set& set_0, const Set& set_1) {
//     Set result;

//     std::for_each(std::begin(set_0), std::end(set_0), [&] (const Variant& value) {
//         if (set_1.search(value) != set_1.nil()) {
//             result.insert(value);
//         }
//     });

//     std::for_each(std::begin(set_1), std::end(set_1), [&] (const Variant& value) {
//         if (set_0.search(value) != set_0.nil()) {
//             result.insert(value);
//         }
//     });

//     return result;
// }

// Set SetOperations::diference_op(const Set& set_0, const Set& set_1) {
//     Set result;

//     std::for_each(std::begin(set_0), std::end(set_0), [&] (const Variant& value) {
//         if (set_1.search(value) == set_1.nil()) {
//             result.insert(value);
//         }
//     });

//     return result;
// }

// Set SetOperations::xor_op(const Set& set_0, const Set& set_1) {
//     Set result;

//     std::for_each(std::begin(set_0), std::end(set_0), [&] (const Variant& value) {
//         if (set_1.search(value) == set_1.nil()) {
//             result.insert(value);
//         }
//     });

//     std::for_each(std::begin(set_1), std::end(set_1), [&] (const Variant& value) {
//         if (set_0.search(value) == set_0.nil()) {
//             result.insert(value);
//         }
//     });

//     return result;
// }