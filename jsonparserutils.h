#pragma once

#define JSON_NODE_GET_OBJECT(n) (JSON_NODE_HOLDS_OBJECT(n) ? json_node_get_object(n) : NULL)
#define JSON_OBJECT_GET_MEMBER_STRING(o,m) (json_object_has_member(o, m) ? json_object_get_string_member(o, m) : NULL)
#define JSON_OBJECT_GET_MEMBER_ARRAY(o, m) (json_object_has_member(o, m) ? json_object_get_array_member(o, m) : NULL)
#define JSON_OBJECT_GET_MEMBER_OBJECT(o, m) (json_object_has_member(o, m) ? json_object_get_object_member(o, m) : NULL)
#define JSON_OBJECT_GET_MEMBER_INT(o, m) (json_object_has_member(o, m) ? json_object_get_int_member(o, m) : -1)
