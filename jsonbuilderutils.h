#pragma once

#define JSONBUILDER_ADD_INT(b, n, v) {json_builder_set_member_name(b, n);\
                                     json_builder_add_int_value(b, (int) v);}

#define JSONBUILDER_ADD_STRING(b, n, v) {json_builder_set_member_name(b, n);\
	                                    json_builder_add_string_value(b, v);}

#define JSONBUILDER_ADD_BOOL(b, n, v) {json_builder_set_member_name(b, n);\
	                                  json_builder_add_boolean_value(b, v);}

#define JSONBUILDER_START_OBJECT(b, n) {json_builder_set_member_name(b, n);\
                                       json_builder_begin_object(b);}

#define JSONBUILDER_START_ARRAY(b, n) {json_builder_set_member_name(b, n);\
                                      json_builder_begin_array(b);}

static gchar* jsonbuilder_freetostring(JsonBuilder* jsonbuilder, gsize* jsonlen) {
	JsonNode* rootnode = json_builder_get_root(jsonbuilder);
	JsonGenerator* generator = json_generator_new();
	json_generator_set_root(generator, rootnode);

	gchar* json = json_generator_to_data(generator, jsonlen);
	g_object_unref(generator);
	g_object_unref(jsonbuilder);
	return json;
}
