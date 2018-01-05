/*
 * OWL - an OCaml numerical library for scientific computing
 * Copyright (c) 2016-2017 Liang Wang <liang.wang@cl.cam.ac.uk>
 */

#ifndef OWL_STATS_H
#define OWL_STATS_H

#include <math.h>
#include <limits.h>


// SFMT PRNG and its internal state

#include "SFMT.h"

extern sfmt_t sfmt_state;

#define sfmt_rand32 sfmt_genrand_uint32(&sfmt_state)

#define sfmt_rand64 sfmt_genrand_uint64(&sfmt_state)

#define sfmt_f32_1 sfmt_genrand_real4(&sfmt_state)

#define sfmt_f32_2 sfmt_genrand_real5(&sfmt_state)

#define sfmt_f32_3 sfmt_genrand_real6(&sfmt_state)

#define sfmt_f64_1 sfmt_genrand_real1(&sfmt_state)

#define sfmt_f64_2 sfmt_genrand_real2(&sfmt_state)

#define sfmt_f64_3 sfmt_genrand_real3(&sfmt_state)

// Various PRNG and functions

#define f32_exponential std_exp_rvs()

#define f64_exponential std_exp_rvs()

#define f32_gaussian std_gaussian_rvs()

#define f64_gaussian std_gaussian_rvs()

extern void ziggurat_init();

/** Uniform distribution **/

/** Exponential distribution **/

extern double std_exp_rvs();

extern double exp_rvs(double lambda);

extern double exp_pdf(double x, double lambda);

extern double exp_logpdf(double x, double lambda);

extern double exp_cdf(double x, double lambda);

extern double exp_logcdf(double x, double lambda);

extern double exp_ppf(double q, double lambda);

extern double exp_sf(double x, double lambda);

extern double exp_logsf(double x, double lambda);

extern double exp_isf(double q, double lambda);

extern double exp_entropy(double sigma);

/** Gaussian distribution **/

extern double std_gaussian_rvs();

extern double gaussian_rvs(double mu, double sigma);

extern double gaussian_pdf(double x, double mu, double sigma);

extern double gaussian_logpdf(double x, double mu, double sigma);

extern double gaussian_cdf(double x, double mu, double sigma);

extern double gaussian_logcdf(double x, double mu, double sigma);

extern double gaussian_ppf(double q, double mu, double sigma);

extern double gaussian_sf(double x, double mu, double sigma);

extern double gaussian_logsf(double x, double mu, double sigma);

extern double gaussian_isf(double q, double mu, double sigma);

extern double gaussian_entropy(double sigma);

/** Gamma distribution **/

extern double std_gamma_rvs(double shape);

extern double gamma_rvs(double shape, double scale);

extern double gamma_pdf(double x, double shape, double scale);

extern double gamma_logpdf(double x, double shape, double scale);

extern double gamma_cdf(double x, double shape, double scale);

extern double gamma_logcdf(double x, double shape, double scale);

extern double gamma_ppl(double q, double shape, double scale);

extern double gamma_sf(double x, double shape, double scale);

extern double gamma_logsf(double x, double shape, double scale);

extern double gamma_isf(double q, double shape, double scale);

extern double gamma_entropy(double shape, double scale);

/** Beta distribution **/

extern double beta_rvs(double a, double b);

extern double beta_pdf(double x, double a, double b);

extern double beta_logpdf(double x, double a, double b);

extern double beta_cdf(double x, double a, double b);

extern double beta_logcdf(double x, double a, double b);

extern double beta_ppl(double q, double a, double b);

extern double beta_sf(double x, double a, double b);

extern double beta_logsf(double x, double a, double b);

extern double beta_isf(double q, double a, double b);

extern double beta_entropy(double a, double b);

/** Chi-squared distribution **/

extern double chisquare_rvs(double);

/** Noncentral Chi-squared distribution **/

extern double noncentral_chisquare_rvs(double, double);

/** F distribution **/

extern double f_rvs(double, double);

/** Noncentral F distribution **/

extern double noncentral_f_rvs(double, double, double);

/** Binomial distribution **/

// TODO

/** Negative Binomial distribution **/

extern long negative_binomial_rvs(double, double);

/** Poisson distribution **/

extern long poisson_rvs(double);

/** Cauchy distribution **/

extern double std_cauchy_rvs();

extern double cauchy_rvs(double loc, double scale);

extern double cauchy_pdf(double x, double loc, double scale);

extern double cauchy_logpdf(double x, double loc, double scale);

extern double cauchy_cdf(double x, double loc, double scale);

extern double cauchy_logcdf(double x, double loc, double scale);

extern double cauchy_ppl(double q, double loc, double scale);

extern double cauchy_sf(double x, double loc, double scale);

extern double cauchy_logsf(double x, double loc, double scale);

extern double cauchy_isf(double q, double loc, double scale);

extern double cauchy_entropy(double scale);

/** Student's t distribution **/

extern double std_t_rvs(double df);

extern double t_rvs(double df, double loc, double scale);

extern double t_pdf(double x, double df, double loc, double scale);

extern double t_logpdf(double x, double df, double loc, double scale);

extern double t_cdf(double x, double df, double loc, double scale);

extern double t_logcdf(double x, double df, double loc, double scale);

extern double t_ppl(double q, double df, double loc, double scale);

extern double t_sf(double x, double df, double loc, double scale);

extern double t_logsf(double x, double df, double loc, double scale);

extern double t_isf(double q, double df, double loc, double scale);

extern double t_entropy(double df);

/** von Mises distribution **/

extern double vonmises_rvs(double, double);

/** Pareto distribution **/

extern double pareto_rvs(double);

/** Weibull distribution **/

extern double weibull_rvs(double);

/** Power distribution **/

extern double power_rvs(double);

/** Laplace distribution **/

extern double laplace_rvs(double, double);

/** Gumbel distribution **/

extern double gumbel_rvs(double, double);

/** Logistic distribution **/

extern double logistic_rvs(double, double);

/** Log-normal distribution **/

extern double lognormal_rvs(double, double);

/** Rayleigh distribution **/

extern double rayleigh_rvs(double);

/** Wald distribution **/

extern double wald_rvs(double, double);

/** Zipf distribution **/

extern long zipf_rvs(double);

/** Geometric distribution **/

extern long geometric_rvs(double);

/** Hypergeometric distribution **/

extern long hypergeometric_rvs(long, long, long);

/** Triangular distribution **/

extern double triangular_rvs(double, double, double);

/** Log-Series distribution **/

extern long logseries_rvs(double);

/** Some helper functions **/

extern double loggam(double x);


#endif // OWL_STATS_H
