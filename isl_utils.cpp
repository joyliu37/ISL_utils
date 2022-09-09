#include "isl_utils.hpp"
#include <regex>
#include <limits>
#include <iostream>

isl_multi_aff* cpy(isl_multi_aff* const s) {
  return isl_multi_aff_copy(s);
}

isl_multi_union_pw_aff* cpy(isl_multi_union_pw_aff* const s) {
  return isl_multi_union_pw_aff_copy(s);
}

isl_local_space* cpy(isl_local_space* const s) {
  return isl_local_space_copy(s);
}

isl_pw_aff* cpy(isl_pw_aff* const s) {
  return isl_pw_aff_copy(s);
}

isl_constraint* cpy(isl_constraint* const s) {
  return isl_constraint_copy(s);
}

isl_basic_map* cpy(isl_basic_map* const s) {
  return isl_basic_map_copy(s);
}
isl_schedule* cpy(isl_schedule* const s) {
  return isl_schedule_copy(s);
}

isl_pw_multi_aff* cpy(isl_pw_multi_aff* const s) {
  return isl_pw_multi_aff_copy(s);
}

isl_qpolynomial* cpy(isl_qpolynomial* const s) {
  return isl_qpolynomial_copy(s);
}

isl_union_pw_qpolynomial* cpy(isl_union_pw_qpolynomial* const s) {
  return isl_union_pw_qpolynomial_copy(s);
}

isl_pw_qpolynomial* cpy(isl_pw_qpolynomial* const s) {
  return isl_pw_qpolynomial_copy(s);
}

isl_union_pw_qpolynomial_fold* cpy(isl_union_pw_qpolynomial_fold* const s) {
  return isl_union_pw_qpolynomial_fold_copy(s);
}

isl_pw_qpolynomial_fold* cpy(isl_pw_qpolynomial_fold* const s) {
  return isl_pw_qpolynomial_fold_copy(s);
}

isl_point* cpy(isl_point* const s) {
  return isl_point_copy(s);
}

isl_space* cpy(isl_space* const s) {
  return isl_space_copy(s);
}

isl_basic_set* cpy(isl_basic_set* const b) {
  return isl_basic_set_copy(b);
}

isl_set* cpy(isl_set* const b) {
  return isl_set_copy(b);
}

isl_union_set* cpy(isl_union_set* const b) {
  return isl_union_set_copy(b);
}

isl_union_map* cpy(isl_union_map* const b) {
  return isl_union_map_copy(b);
}

isl_map* cpy(isl_map* const b) {
  return isl_map_copy(b);
}

isl_val* cpy(isl_val* const b) {
  return isl_val_copy(b);
}

isl_aff* cpy(isl_aff* const b) {
  return isl_aff_copy(b);
}

isl_ctx* ctx(isl_multi_aff* const m) {
  return isl_multi_aff_get_ctx(m);
}

isl_ctx* ctx(isl_set* const m) {
  return isl_set_get_ctx(m);
}

isl_ctx* ctx(isl_pw_aff* const m) {
  return isl_pw_aff_get_ctx(m);
}

isl_ctx* ctx(isl_union_set* const m) {
  return isl_union_set_get_ctx(m);
}

isl_ctx* ctx(isl_point* const m) {
  return isl_point_get_ctx(m);
}

isl_ctx* ctx(isl_constraint* const m) {
  return isl_constraint_get_ctx(m);
}

isl_ctx* ctx(isl_basic_map* const m) {
  return isl_basic_map_get_ctx(m);
}

isl_ctx* ctx(isl_basic_set* const m) {
  return isl_basic_set_get_ctx(m);
}

isl_ctx* ctx(isl_space* const m) {
  return isl_space_get_ctx(m);
}

isl_ctx* ctx(isl_qpolynomial* const m) {
  return isl_qpolynomial_get_ctx(m);
}


isl_ctx* ctx(isl_union_pw_qpolynomial* const m) {
  return isl_union_pw_qpolynomial_get_ctx(m);
}

isl_ctx* ctx(isl_aff* const m) {
  return isl_aff_get_ctx(m);
}

isl_ctx* ctx(isl_val* const m) {
  return isl_val_get_ctx(m);
}

isl_ctx* ctx(isl_map* const m) {
  return isl_map_get_ctx(m);
}

isl_ctx* ctx(umap* const m) {
  return isl_union_map_get_ctx(m);
}

isl_ctx* ctx(isl_schedule* const m) {
  return isl_schedule_get_ctx(m);
}

isl_ctx* ctx(isl_union_pw_qpolynomial_fold* const m) {
  return isl_union_pw_qpolynomial_fold_get_ctx(m);
}

isl_ctx* ctx(isl_pw_qpolynomial_fold* const m) {
  return isl_pw_qpolynomial_fold_get_ctx(m);
}

isl_ctx* ctx(isl_pw_qpolynomial* const m) {
  return isl_pw_qpolynomial_get_ctx(m);
}

std::string str(isl_basic_map* const m) {
  auto ctx = isl_basic_map_get_ctx(m);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_basic_map(p, cpy(m));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_map* const m) {
  auto ctx = isl_map_get_ctx(m);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_map(p, cpy(m));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_id* const id) {
  assert(id != nullptr);
  return std::string(isl_id_to_str(id));
}

std::string str(isl_local_space* const m) {
  auto ctx = isl_local_space_get_ctx(m);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_local_space(p, cpy(m));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(umap* const m) {
  auto ctx = isl_union_map_get_ctx(m);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_union_map(p, cpy(m));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_union_set* const m) {
  auto ctx = isl_union_set_get_ctx(m);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_union_set(p, cpy(m));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_basic_set* const m) {
  assert(m != nullptr);
  auto ctx = isl_basic_set_get_ctx(m);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_basic_set(p, cpy(m));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_set* const s) {
  assert(s != nullptr);
  auto ctx = isl_set_get_ctx(s);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_set(p, cpy(s));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_union_pw_qpolynomial_fold* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_union_pw_qpolynomial_fold(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}
std::string str(isl_pw_qpolynomial_fold* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_pw_qpolynomial_fold(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

std::string str(isl_pw_qpolynomial* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_pw_qpolynomial(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}
std::string str(isl_val* const bset) {
  assert(bset != nullptr);

  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_val(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}


std::string str(isl_multi_aff* const pma) {
  auto ctx = isl_multi_aff_get_ctx(pma);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_multi_aff(p, cpy(pma));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_pw_multi_aff* const pma) {
  auto ctx = isl_pw_multi_aff_get_ctx(pma);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_pw_multi_aff(p, cpy(pma));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_union_pw_multi_aff* const pma) {
  auto ctx = isl_union_pw_multi_aff_get_ctx(pma);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_union_pw_multi_aff(p, pma);
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;

}
std::string str(isl_multi_union_pw_aff* const mupa) {
  auto ctx = isl_multi_union_pw_aff_get_ctx(mupa);
  isl_printer *p;
  p = isl_printer_to_str(ctx);
  p = isl_printer_print_multi_union_pw_aff(p, cpy(mupa));
  char* rs = isl_printer_get_str(p);
  isl_printer_free(p);
  std::string r(rs);
  free(rs);

  return r;
}

std::string str(isl_pw_aff* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_pw_aff(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}


std::string str(isl_point* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_point(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

std::string str(isl_schedule* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_schedule(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

std::string str(isl_constraint* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_constraint(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

std::string str(isl_space* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_space(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

std::string str(isl_union_pw_qpolynomial* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_union_pw_qpolynomial(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

std::string str(isl_qpolynomial* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_qpolynomial(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

std::string str(isl_aff* const bset) {
  assert(bset != nullptr);

  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_print_aff(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

isl_stat get_set(isl_set* m, void* user) {
  auto* vm = (vector<isl_set*>*) user;
  vm->push_back((m));
  return isl_stat_ok;
}

vector<isl_set*> get_sets(isl_union_set* m) {
  assert(m != nullptr);

  vector<isl_set*> map_vec;
  isl_union_set_foreach_set(m, get_set, &map_vec);

  return map_vec;
}

isl_set* to_set(isl_union_set* const m) {
  auto ss = get_sets(m);
  assert(ss.size() == 1);
  return ss.at(0);
}

isl_set* to_set(isl_basic_set* const m) {
  return isl_set_from_basic_set(cpy(m));
}

isl_set* to_set(isl_point* const m) {
  return isl_set_from_point(cpy(m));
}

isl_union_set* to_uset(isl_set* const m) {
  return isl_union_set_from_set(cpy(m));
}


isl_map* to_map(isl_basic_map* const m) {
  return isl_map_from_basic_map(m);
}


isl_stat get_maps(isl_map* m, void* user) {
  auto* vm = (vector<isl_map*>*) user;
  vm->push_back((m));
  return isl_stat_ok;
}

isl_map* to_map(isl_union_map* const m) {
  assert(m != nullptr);

  vector<isl_map*> map_vec;
  isl_union_map_foreach_map(m, get_maps, &map_vec);

  assert(map_vec.size() == 1);
  return map_vec.at(0);
}

isl_union_map* to_umap(isl_map* const m) {
  return isl_union_map_from_map(cpy(m));
}

isl_union_map* to_umap(isl_union_set* const m) {
  return isl_union_map_from_domain_and_range(cpy(m), cpy(m));
}

isl_space* get_space(isl_basic_map* const m) {
  return isl_basic_map_get_space(m);
}

isl_space* get_space(isl_basic_set* const m) {
  return isl_basic_set_get_space(m);
}

isl_space* get_space(isl_aff* const m) {
  return isl_aff_get_space(m);
}

isl_space* get_space(isl_constraint* const m) {
  return isl_constraint_get_space(m);
}

isl_space* get_space(isl_union_map* const m) {
  return isl_union_map_get_space(m);
}

isl_space* get_space(isl_map* const m) {
  return isl_map_get_space(m);
}

isl_space* get_space(isl_union_set* const m) {
  assert(m != nullptr);
  return isl_union_set_get_space(m);
}

isl_space* get_space(isl_set* const m) {
  assert(m != nullptr);
  return isl_set_get_space(m);
}

std::string name(isl_set* const s) {
  return name(get_space(s));
}

std::string name(isl_union_set* const s) {
  return name(get_space(s));
}

std::string domain_name(isl_basic_map* const s) {
  return domain_name(get_space(s));
}

std::string range_name(isl_basic_map* const s) {
  return range_name(get_space(s));
}

std::string domain_name(isl_map* const s) {
  return domain_name(get_space(s));
}

std::string domain_name(umap* const s) {
  return domain_name(get_space(to_map(s)));
}

std::string range_name(isl_map* const s) {
  return range_name(get_space(s));
}

std::string name(isl_space* const s) {
  return std::string(isl_id_to_str(isl_space_get_tuple_id(s, isl_dim_set)));
}

std::string domain_name(isl_space* const s) {
  return std::string(isl_id_to_str(isl_space_get_tuple_id(s, isl_dim_in)));
}

std::string range_name(isl_space* const s) {
  if(isl_space_has_tuple_id(s, isl_dim_out))
    return std::string(isl_id_to_str(isl_space_get_tuple_id(s, isl_dim_out)));
  else
    return "";
}

isl_stat get_pw_multi_aff_piece(isl_set* dom, isl_multi_aff* domain, void* user) {
  vector<pair<isl_set*, isl_multi_aff*> >* v =
    (vector<pair<isl_set*, isl_multi_aff*> >*) user;
  v->push_back({dom, domain});
  return isl_stat_ok;
}


vector<pair<isl_set*, isl_multi_aff*> >
get_pieces(isl_pw_multi_aff* lm) {
  assert(lm != nullptr);
  vector<pair<isl_set*, isl_multi_aff*> > pieces;
  isl_pw_multi_aff_foreach_piece(lm, get_pw_multi_aff_piece, &pieces);
  return pieces;
}

int get_size(isl_multi_aff* const m) {
  return isl_multi_aff_dim(m, isl_dim_out);
}

vector<isl_aff*> get_aff_vec(isl_map* m) {
  vector<isl_aff*> ret;
  auto cpy_m = cpy(m);
  auto lm = isl_pw_multi_aff_from_map(cpy_m);
  if (!lm)
      return ret;
  vector<pair<isl_set*, isl_multi_aff*> > pieces =
    get_pieces(lm);
  assert(pieces.size() == 1);
  auto saff = pieces.at(0).second;
  for (int i = 0; i < get_size(saff); i ++) {
    auto aff = isl_multi_aff_get_aff(saff, i);
    ret.push_back(aff);
  }
  return ret;
}

isl_id* id(isl_ctx* c, const std::string& s) {
  return isl_id_alloc(c, s.c_str(), nullptr);
}

int num_dims(isl_space* const s) {
  assert(isl_space_is_set(s));
  int ndims = isl_space_dim(s, isl_dim_set);
  return ndims;
}

int num_dims(isl_basic_set* const s) {
  return num_dims(get_space(s));
}

int num_dims(isl_set* const s) {
  return num_dims(get_space(s));
}

int num_out_dims(isl_space* const s) {
  assert(isl_space_is_map(s));
  int ndims = isl_space_dim(s, isl_dim_out);
  return ndims;
}

int num_out_dims(isl_local_space* const s) {
  assert(!isl_local_space_is_set(s));
  int ndims = isl_local_space_dim(s, isl_dim_out);
  return ndims;
}

int num_out_dims(isl_map* const m) {
  return num_out_dims(get_space(m));
}


int num_in_dims(isl_local_space* const s) {
  assert(!isl_local_space_is_set(s));
  int ndims = isl_local_space_dim(s, isl_dim_in);
  return ndims;
}

int num_in_dims(isl_space* const s) {
  assert(isl_space_is_map(s));
  int ndims = isl_space_dim(s, isl_dim_in);
  return ndims;
}

int num_in_dims(isl_map* const s) {
  return num_in_dims(get_space((s)));
}

isl_val* neg(isl_val* a) {
  return isl_val_neg(cpy(a));
}

isl_val* sub(isl_val* a, isl_val* b) {
  return isl_val_sub(cpy(a), cpy(b));
}

isl_val* add(isl_val* a, isl_val* b) {
  return isl_val_add(cpy(a), cpy(b));
}

isl_val* mul(isl_val* a, isl_val* b) {
  return isl_val_mul(cpy(a), cpy(b));
}

isl_val* one(isl_ctx* c) {
  return isl_val_one(c);
}

isl_val* zero(isl_ctx* c) {
  return isl_val_zero(c);
}
isl_val* negone(isl_ctx* c) {
  return isl_val_negone(c);
}

isl_point* lexminpt(isl_set* const m0) {
  return sample(lexmin(m0));
}

isl_point* lexminpt(uset* const m0) {
  return sample(lexmin(m0));
}

isl_point* lexmaxpt(isl_set* const m0) {
  return sample(lexmax(m0));
}

isl_point* lexmaxpt(uset* const m0) {
  return sample(lexmax(m0));
}

isl_union_set* lexmax(isl_union_set* const m0) {
  return isl_union_set_lexmax(cpy(m0));
}

isl_set* lexmax(isl_set* const m0) {
  return isl_set_lexmax(cpy(m0));
}

umap* lexmax(umap* const m0) {
  return isl_union_map_lexmax(cpy(m0));
}

isl_map* lexmax(isl_map* const m0) {
  return isl_map_lexmax(cpy(m0));
}

isl_set* lexmin(isl_set* const m0) {
  return isl_set_lexmin(cpy(m0));
}

isl_union_set* lexmin(uset* const m0) {
  return isl_union_set_lexmin(cpy(m0));
}
umap* lexmin(umap* const m0) {
  return isl_union_map_lexmin(cpy(m0));
}

isl_map* lexmin(isl_map* const m0) {
  return isl_map_lexmin(cpy(m0));
}

isl_point* sample(isl_basic_set* s) {
  return isl_basic_set_sample_point(cpy(s));
}

isl_point* sample(isl_union_set* s) {
  return isl_union_set_sample_point(cpy(s));
}

isl_point* sample(isl_set* s) {
  return isl_set_sample_point(cpy(s));
}

isl_val* coord(isl_point* const p, const int pos) {
  return isl_point_get_coordinate_val(p, isl_dim_set, pos);
}

isl_val* lexminval(isl_set* const m0) {
  return coord(lexminpt(m0), 0);
}

isl_val* lexmaxval(isl_set* const m0) {
  return coord(lexmaxpt(m0), 0);
}

isl_union_set* domain(isl_union_map* const m) {
  return isl_union_map_domain(cpy(m));
}

isl_union_set* range(isl_union_map* const m) {
  return isl_union_map_range(cpy(m));
}

isl_set* range(isl_map* const m) {
  return isl_map_range(cpy(m));
}

isl_set* domain(isl_map* const m) {
  return isl_map_domain(cpy(m));
}

isl_map* inv(isl_map* const m0) {
  return isl_map_reverse(cpy(m0));
}

isl_union_map* inv(isl_union_map* const m0) {
  return isl_union_map_reverse(cpy(m0));
}

isl_union_map* dot(isl_map* const m0, isl_union_map* const m1) {
  return isl_union_map_apply_range(to_umap(m0), cpy(m1));
}

isl_union_map* dot(isl_union_map* const m0, isl_map* const m1) {
  return isl_union_map_apply_range(cpy(m0), to_umap(m1));
}

isl_map* dot(isl_map* const m0, isl_map* const m1) {
  return isl_map_apply_range(cpy(m0), cpy(m1));
}

isl_set* project_all_but(isl_set* const dmap, const int d) {

  auto m = cpy(dmap);
  auto ct = ctx(dmap);

  string dname = "";
  if (isl_set_get_tuple_id(dmap) != nullptr) {
    dname = name(m);
  }

  if (d != 0) {
    m = isl_set_project_out(m, isl_dim_set, 0, d);
  }

  int in_dim = num_dims(get_space(m));

  m = isl_set_project_out(m, isl_dim_set, 1, in_dim - 1);

  assert(num_dims(get_space(m)) == 1);

  if (isl_set_get_tuple_id(dmap) != nullptr) {
    isl_set_set_tuple_id(m, id(ct, dname));
  }

  return m;
}


isl_stat get_pw_qpolynomial_fold(isl_pw_qpolynomial_fold* qp, void* user) {
  vector<isl_pw_qpolynomial_fold*>* v = (vector<isl_pw_qpolynomial_fold*>*) user;
  v->push_back(qp);

  return isl_stat_ok;
}

vector<isl_pw_qpolynomial_fold*>
get_polynomial_folds(isl_union_pw_qpolynomial_fold* p) {
  vector<isl_pw_qpolynomial_fold*> terms;
  isl_union_pw_qpolynomial_fold_foreach_pw_qpolynomial_fold(p, get_pw_qpolynomial_fold, &terms);
  return terms;
}

std::string codegen_c(isl_pw_qpolynomial_fold* const bset) {
  auto context = ctx(bset);
  isl_printer *p;
  p = isl_printer_to_str(context);
  p = isl_printer_set_output_format(p, ISL_FORMAT_C);
  p = isl_printer_print_pw_qpolynomial_fold(p, cpy(bset));

  char* rs = isl_printer_get_str(p);
  std::string r(rs);
  isl_printer_free(p);
  free(rs);
  return r;
}

vector<isl_map*> get_maps(isl_union_map* m) {
  assert(m != nullptr);

  vector<isl_map*> map_vec;
  isl_union_map_foreach_map(m, get_maps, &map_vec);

  return map_vec;
}

map<string, isl_map*> get_maps_in_map(isl_union_map* m) {
  assert(m != nullptr);

  vector<isl_map*> map_vec;
  isl_union_map_foreach_map(m, get_maps, &map_vec);
  map<string, isl_map*> map_map;
  for (auto m: map_vec) {
      map_map.insert(make_pair(domain_name(m), m));
  }

  return map_map;
}


std::string codegen_c(isl_union_map* res) {
  auto maps = get_maps(res);
  if (maps.size() == 0) {
    return "";
  }

  auto rep = *std::begin(maps);
  auto range_rep = range(rep);
  int dim = num_dims(range_rep);

  vector<string> vars;
  for (int d = 0; d < dim; d++) {
    vars.push_back("t" + std::to_string(d));
  }
  isl_ast_build* build = isl_ast_build_alloc(isl_union_map_get_ctx(res));
  isl_ast_node* code =
    isl_ast_build_node_from_schedule_map(build, cpy(res));

  char* code_str = isl_ast_node_to_C_str(code);
  std::string code_string(code_str);
  free(code_str);

  isl_ast_build_free(build);

  return code_string;
}

bool is_int( const std::string& str ) { // check with regex (does not accept leading zeroes before first digit)

    static constexpr auto max_digits = std::numeric_limits<int>::digits10 ;
    static const std::string ub = std::to_string(max_digits-1) ;
    static const std::regex int_re( "^\\s*([+-]?[1-9]\\d{0," + ub + "}|0)\\s*$" ) ;

    return std::regex_match( str, int_re ) ;
}

bool is_number(string s) {
  return is_int(s);
}

int safe_stoi(const string s) {
  if (is_number(s)) {
    return stoi(s);
  }
  std::cout << "String: " << s << " is not a number!" << std::endl;
  assert(false);
  return -1;
}


int bnd_int(isl_union_pw_qpolynomial_fold* bound) {
  auto folds  = get_polynomial_folds(bound);
  int bint;
  if (folds.size() == 0) {
    bint = 0;
  } else {
    assert(folds.size() == 1);
    string str_bnd = codegen_c(folds[0]);

    if (is_number(str_bnd)) {
      bint = safe_stoi(str_bnd);
      return bint;
    } else {
      std::regex cm("\\((.*)\\)/(.*)");
      std::smatch match;
      auto res = regex_search(str_bnd, match, cm);
      assert(res);
      std::cout << match[1] << ", " << match[2] << std::endl;
      return safe_stoi(match[1]) / safe_stoi(match[2]);
    }
  }
  return bint;
}

int int_lower_bound(isl_union_pw_qpolynomial* range_card) {
  auto is_tight = isl_bool_false;
  auto bound = isl_union_pw_qpolynomial_bound(cpy(range_card), isl_fold_min, &is_tight);
  return bnd_int(bound);
}

int int_upper_bound(isl_union_pw_qpolynomial* range_card) {
  auto is_tight = isl_bool_false;
  auto bound = isl_union_pw_qpolynomial_bound(cpy(range_card), isl_fold_max, &is_tight);
  return bnd_int(bound);
}

uset* rdset(isl_ctx* ctx, const std::string& s) {
  auto res = isl_union_set_read_from_str(ctx, s.c_str());
  if (res == nullptr) {
    std::cout << "Error: Bad string for isl_map: " << s << std::endl;
    assert(false);
  }
  return res;
}

umap* rdmap(isl_ctx* ctx, const std::string& s) {
  auto res = isl_union_map_read_from_str(ctx, s.c_str());
  if (res == nullptr) {
    std::cout << "Error: Bad string for isl_map: " << s << std::endl;
    assert(false);
  }
  return res;
}
