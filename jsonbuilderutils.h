#pragma once

#define JSONBUILDER_ADD_INT(b, n, v) {json_builder_set_member_name(b, n);\
                                     json_builder_add_int_value(b, (int) v);}

#define JSONBUILDER_ADD_DOUBLE(b, n, v) {json_builder_set_member_name(b, n);\
                                     json_builder_add_double_value(b, (double) v);}

#define JSONBUILDER_ADD_STRING(b, n, v) {json_builder_set_member_name(b, n);\
	                                    json_builder_add_string_value(b, v);}

#define JSONBUILDER_ADD_BOOL(b, n, v) {json_builder_set_member_name(b, n);\
	                                  json_builder_add_boolean_value(b, v);}

#define JSONBUILDER_START_OBJECT(b, n) {json_builder_set_member_name(b, n);\
                                       json_builder_begin_object(b);}

#define JSONBUILDER_START_ARRAY(b, n) {json_builder_set_member_name(b, n);\
                                      json_builder_begin_array(b);}

static gchar* jsonbuilder_freetostring(JsonBuilder* jsonbuilder, gsize* jsonlen,
		gboolean pretty) {
	JsonNode* rootnode = json_builder_get_root(jsonbuilder);
	JsonGenerator* generator = json_generator_new();
	json_generator_set_root(generator, rootnode);
	json_generator_set_pretty(generator, pretty);

	gchar* json = json_generator_to_data(generator, jsonlen);
	g_object_unref(generator);
	g_object_unref(jsonbuilder);
	return json;
}

static gboolean jsonbuilder_writetofile(JsonBuilder*, gboolean, const gchar*) __attribute__((unused));
static gboolean jsonbuilder_writetofile(JsonBuilder* jsonbuilder,
		gboolean pretty, const gchar* path) {
	gsize jsonlen;
	gchar* json = jsonbuilder_freetostring(jsonbuilder, &jsonlen, TRUE);
	g_file_set_contents(path, json, jsonlen, NULL);
	return TRUE;
}
