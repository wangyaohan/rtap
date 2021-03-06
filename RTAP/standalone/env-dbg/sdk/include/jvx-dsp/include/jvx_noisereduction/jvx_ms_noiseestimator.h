/*
 *****************************************************
 * Filename: jvx_ms_noiseEstimator.h
 *****************************************************
 * Project: RTProc-ESP (Echtzeit-Software-Plattform) *
 *****************************************************
 * Description: Definition of the C functions for the minimum statistics implementation.
  *				The set of functions enables initialize, terminate and a compute function.
 *				The code is derived from the original paper
 *				"Noise Power Spectral Density Estimation Based on Optimal Smoothing and Minimum Statistics",
 *				by Rainer Martin in 2001 in IEEE Transactions on Speech and Audio Processing, vol. 9, pp. 504-512, July 2001.
 *				Note that there are some inaccuracies in the desccription of the original algorithm
 *				which makes a complete implementation of the proposed method impossible. The
 *				version used here is somewhat modified.
 *
 *****************************************************
 * Developed by JAVOX SOLUTIONS GMBH, 2012           *
 *****************************************************
 * COPYRIGHT BY JAVOX SOLUTION GMBH                  *
 *****************************************************
 * Contact: rtproc@javox-solutions.com               *
 *****************************************************
*/


#ifndef _JVX_MINIMUMSTATISTICS_H__
#define _JVX_MINIMUMSTATISTICS_H__

#include "jvx_dsp_base.h"
#include "jvx_ms_noiseestimator_config.h"

//! Initialize the MS functionality. Specify fft length and subwindow setup. The returned handle shall be used in the following
jvxDspBaseErrorType jvx_ms_noiseEstimator_init(jvxHandle** handle, jvxInt32 fftSize, jvxInt32 numFramesSubwindow, jvxInt32 numSubWindows);

//! Initialize the MS functionality. Almost all parameters can be setup based on the passed struct Hcv. The returned handle shall be used in the following
jvxDspBaseErrorType jvx_ms_noiseEstimator_init_params(jvxHandle** handle, jvx_ms_noiseEstimator_config* Hcv);

//! Update the main parameters which allow online modification during operation.
jvxDspBaseErrorType jvx_ms_noiseEstimator_update_params(jvxHandle* handle, jvx_ms_noiseEstimator_runtime* Hcv, jvxBool doset);

//! Compute the noise PSD.
jvxDspBaseErrorType jvx_ms_noiseEstimator_process_fft(jvxHandle* handle, jvxData* oneFreqBuffer_re, jvxData* oneFreqBuffer_im, jvxData* noisePSD_out, jvxData* debugOut);

//! Compute the noise PSD.
jvxDspBaseErrorType jvx_ms_noiseEstimator_process_fft2(jvxHandle* handle, jvxDataCplx* oneFreqBuffer, jvxData* noisePSD_out, jvxData* debugOut);

//! Compute the noise PSD.
jvxDspBaseErrorType jvx_ms_noiseEstimator_process_psd(jvxHandle* handle, jvxData* oneFreqBuffer, jvxData* noisePSD_out, jvxData* debugOut);

//! Terminate the object. This also deallocated all reserved memory
jvxDspBaseErrorType jvx_ms_noiseEstimator_terminate(jvxHandle* handle);

#endif
