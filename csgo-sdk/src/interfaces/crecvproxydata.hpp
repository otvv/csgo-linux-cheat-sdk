//
// csgo sdk
//

#pragma once

class CRecvProxyData;
struct RecvTable;

using fn = void (*)(CRecvProxyData *, void *, void *);

enum SendPropType
{
  DPT_INT = 0,
  DPT_FLOAT,
  DPT_VECTOR_3D,
  DPT_VECTOR_2D,
  DPT_STRING,
  DPT_ARRAY, // an array of the base types (can't be of datatables).
  DPT_DATA_TABLE,
	DPT_INT64,
	DPT_NUM_SEND_PROP_TYPES
};

struct RecvProp
{
  char *name;
  SendPropType type;
  int flags;
  int string_buffer_size;
  bool inside_array;
  const void *extra_data;
  RecvProp *array_prop;
  void *array_length_alias;
  fn proxy_fn;
  void *data_table_alias_fn;
  RecvTable *data_table;
  int offset;
  int element_stride;
  int elements;
  const char *parent_array_prop_name;
};

struct RecvTable
{
  RecvProp *p_props;
  int num_props;
  void *decoder;
  char *name;
  bool initialized;
  bool in_main_list;
};

class DVariant
{
public:
  union {
    float data_float;
    long data_int;
    char *data_string;
    void *p_data;
    float data_vector[3];
    signed long int_64;
  };
};

class CRecvProxyData
{
public:
  const RecvProp *p_recv_prop;
  DVariant value;
  int element;
  int object_id;
};