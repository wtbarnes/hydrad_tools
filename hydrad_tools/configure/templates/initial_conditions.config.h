// ****
// *
// * #defines for configuring the hydrostatic model
// *
// * (c) Dr. Stephen J. Bradshaw
// *
// * Source code generated by hydrad_tools on {{ date }}
// *
// ****

// **** Output ****
// **** End of Output ****

// **** Physics ****
#include "../../Radiation_Model/source/config.h"
{% if initial_conditions.isothermal -%}
#define ISOTHERMAL
{%- endif %}
{% if initial_conditions.use_poly_fit_gravity and general.poly_fit_gravity is defined -%}
#define USE_POLY_FIT_TO_GRAVITY
#define POLY_FIT_TO_GRAVITY_FILE "poly_fit.gravity"
{%- endif %}

// **** Solver ****
#define EPSILON {{ solver.epsilon | is_required }}

// **** Grid ****
{% if grid.adapt -%}#define ADAPT{%- endif %}
#define MIN_CELLS {{ grid.minimum_cells | is_required }}
#define MAX_CELLS {{ grid.maximum_cells | is_required }}
#define MAX_REFINEMENT_LEVEL {{ grid.maximum_refinement_level | is_required }}
#define MIN_DS {{ grid.minimum_delta_s | is_required | units_filter('cm') }}
#define MAX_VARIATION {{ grid.maximum_variation | is_required + 1.0}}
