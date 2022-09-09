#pragma once

extern "C" {
#include <isl/id.h>
#include <isl/set.h>
#include <isl/flow.h>
#include <isl/polynomial.h>
#include <isl/union_set.h>
#include <isl/union_map.h>
#include <isl/space.h>
#include <isl/schedule.h>
#include <isl/schedule_node.h>
#include <isl/ast_build.h>
#include <isl/val.h>
#include <isl/ilp.h>
#include <isl/options.h>
#include <isl/map.h>
#include <isl/aff.h>
}


typedef isl_union_map umap;
typedef isl_union_set uset;
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using std::vector;
using std::map;
using std::string;
using std::unordered_set;
using std::pair;


isl_pw_aff* cpy(isl_pw_aff* const s);
isl_multi_aff* cpy(isl_multi_aff* const s);
isl_constraint* cpy(isl_constraint* const s);
isl_basic_map* cpy(isl_basic_map* const s);
isl_schedule* cpy(isl_schedule* const s);
isl_pw_multi_aff* cpy(isl_pw_multi_aff* const s);
isl_qpolynomial* cpy(isl_qpolynomial* const s);
isl_union_pw_qpolynomial* cpy(isl_union_pw_qpolynomial* const s);
isl_pw_qpolynomial* cpy(isl_pw_qpolynomial* const s);
isl_union_pw_qpolynomial_fold* cpy(isl_union_pw_qpolynomial_fold* const s);
isl_pw_qpolynomial_fold* cpy(isl_pw_qpolynomial_fold* const s);
isl_point* cpy(isl_point* const s);
isl_space* cpy(isl_space* const s);
isl_local_space* cpy(isl_local_space* const s);
isl_basic_set* cpy(isl_basic_set* const b);
isl_set* cpy(isl_set* const b);
isl_union_set* cpy(isl_union_set* const b);
isl_union_map* cpy(isl_union_map* const b);
isl_map* cpy(isl_map* const b);
isl_val* cpy(isl_val* const b);
isl_aff* cpy(isl_aff* const b);

isl_ctx* ctx(isl_pw_aff* const m);
isl_ctx* ctx(isl_union_set* const m);
isl_ctx* ctx(isl_point* const m);
isl_ctx* ctx(isl_constraint* const m);
isl_ctx* ctx(isl_basic_set* const m);
isl_ctx* ctx(isl_basic_map* const m);
isl_ctx* ctx(isl_set* const m);
isl_ctx* ctx(isl_space* const m);
isl_ctx* ctx(isl_qpolynomial* const m);
isl_ctx* ctx(isl_union_pw_qpolynomial* const m);
isl_ctx* ctx(isl_aff* const m);
isl_ctx* ctx(isl_multi_aff* const m);
isl_ctx* ctx(isl_val* const m);
isl_ctx* ctx(isl_map* const m);
isl_ctx* ctx(umap* const m);
isl_ctx* ctx(isl_schedule* const m);
isl_ctx* ctx(isl_union_pw_qpolynomial_fold* const m);
isl_ctx* ctx(isl_pw_qpolynomial_fold* const m);
isl_ctx* ctx(isl_pw_qpolynomial* const m);


std::string str(isl_basic_set* const id);
std::string str(isl_basic_map* const id);
std::string str(isl_set* const m);
std::string str(isl_union_set* const m);
std::string str(isl_map* const m);
std::string str(umap* const m);
std::string str(isl_id* const id);
std::string str(isl_local_space* const id);
std::string str(isl_pw_multi_aff* const pma);
std::string str(isl_multi_aff* const pma);
std::string str(isl_union_pw_multi_aff* const pma);
std::string str(isl_multi_union_pw_aff* const pma);
std::string str(isl_pw_aff* const bset);
std::string str(isl_point* const bset);
std::string str(isl_schedule* const bset);
std::string str(isl_constraint* const bset);
std::string str(isl_space* const bset);
std::string str(isl_union_pw_qpolynomial* const bset);
std::string str(isl_qpolynomial* const bset);
std::string str(isl_aff* const bset);
std::string str(isl_union_pw_qpolynomial_fold* const bset);
std::string str(isl_pw_qpolynomial_fold* const bset);
std::string str(isl_pw_qpolynomial* const bset);
std::string str(isl_val* const bset);

isl_map* to_map(isl_basic_map* const m);
isl_map* to_map(isl_union_map* const m);
isl_union_map* to_umap(isl_map* const m);
isl_union_map* to_umap(isl_union_set* const m);

isl_set* to_set(isl_union_set* const m);
isl_set* to_set(isl_basic_set* const m);
isl_set* to_set(isl_point* const m);
uset* to_uset(isl_set* const s);

vector<isl_set*> get_sets(isl_union_set* m);

isl_space* get_space(isl_basic_map* const m);
isl_space* get_space(isl_basic_set* const m);
isl_space* get_space(isl_aff* const m) ;
isl_space* get_space(isl_constraint* const m);
isl_space* get_space(isl_union_map* const m);
isl_space* get_space(isl_map* const m);
isl_space* get_space(isl_union_set* const m);
isl_space* get_space(isl_set* const m);

std::string name(isl_set* const s);
std::string name(isl_union_set* const s);
std::string name(isl_space* const s);

std::string domain_name(isl_basic_map* const s);
std::string domain_name(isl_map* const s);
std::string domain_name(umap* const s);
std::string domain_name(isl_space* const s);

std::string range_name(isl_space* const s);
std::string range_name(isl_map* const s);
std::string range_name(isl_basic_map* const s);

int num_dims(isl_space* const s);
int num_dims(isl_basic_set* const s);
int num_dims(isl_set* const s);

int num_in_dims(isl_local_space* const s);
int num_in_dims(isl_space* const s);
int num_in_dims(isl_map* const s);
int num_out_dims(isl_local_space* const s);
int num_out_dims(isl_space* const s);
int num_out_dims(isl_map* const m);

isl_val* neg(isl_val* a);
isl_val* sub(isl_val* a, isl_val* b);
isl_val* add(isl_val* a, isl_val* b);
isl_val* mul(isl_val* a, isl_val* b);
isl_val* one(isl_ctx* c);
isl_val* zero(isl_ctx* c);
isl_val* negone(isl_ctx* c);

isl_val* coord(isl_point* const p, const int pos);

isl_union_set* lexmax(isl_union_set* const m0);
isl_set* lexmax(isl_set* const m0);
umap* lexmax(umap* const m0);
isl_map* lexmax(isl_map* const m0);

isl_set* lexmin(isl_set* const m0);
isl_union_set* lexmin(uset* const m0);
umap* lexmin(umap* const m0);
isl_map* lexmin(isl_map* const m0);

isl_point* sample(isl_basic_set* s);
isl_point* sample(isl_union_set* s);
isl_point* sample(isl_set* s);


isl_point* lexminpt(isl_set* const m0);
isl_point* lexminpt(isl_union_set* const m0);
isl_point* lexmaxpt(isl_set* const m0);
isl_point* lexmaxpt(isl_union_set* const m0);

isl_val* lexminval(isl_set* const m0);
isl_val* lexmaxval(isl_set* const m0);

isl_union_set* domain(isl_union_map* const m);
isl_union_set* range(isl_union_map* const m);
isl_set* domain(isl_map* const m);
isl_set* range(isl_map* const m);


isl_map* inv(isl_map* const m0);
isl_union_map* inv(isl_union_map* const m0);
isl_union_map* dot(isl_map* const m0, isl_union_map* const m1);
isl_union_map* dot(isl_union_map* const m0, isl_map* const m1);
isl_map* dot(isl_map* const m0, isl_map* const m1);

isl_id* id(isl_ctx* c, const std::string& s);

isl_set* project_all_but(isl_set* const dmap, const int d);


std::vector<isl_aff*> get_aff_vec(isl_map* m);

int bnd_int(isl_union_pw_qpolynomial_fold* bound);
int int_lower_bound(isl_union_pw_qpolynomial* range_card);
int int_upper_bound(isl_union_pw_qpolynomial* range_card);


umap* rdmap(isl_ctx* ctx, const std::string& s);
uset* rdset(isl_ctx* ctx, const std::string& s);

vector<isl_map*> get_maps(isl_union_map* m);
map<string, isl_map*> get_maps_in_map(isl_union_map* m);

std::string codegen_c(isl_union_map* res);
