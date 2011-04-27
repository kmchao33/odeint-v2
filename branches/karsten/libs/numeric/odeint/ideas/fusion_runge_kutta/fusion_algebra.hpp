/*
 * fusion_algebra.hpp
 *
 *  Created on: Apr 26, 2011
 *      Author: mario
 */

#ifndef FUSION_ALGEBRA_HPP_
#define FUSION_ALGEBRA_HPP_

#include <boost/array.hpp>


template< size_t n >
struct fusion_algebra
{

    template< typename T , size_t dim >
    inline static void foreach( boost::array< T , dim > &x_tmp , const boost::array< T , dim > &x ,
            const boost::array< double , n > &a ,
            const boost::array< T , dim > *k_vector , const double dt )
    {
        for( size_t i=0 ; i<dim ; ++i )
        {
            x_tmp[i] = x[i];
            for( size_t j = 0 ; j<n ; ++j )
                x_tmp[i] += a[j]*dt*k_vector[j][i];
        }
    }

};




/** hand-wise implementation for performance improvement for n = 1..4 **/

/* !!!!!!!   Actually, this is factor 3 slower with intel compiler, so we don'y use it !!!!!
 *

template<>
struct fusion_algebra< 1 >
{

    template< class state_type >
    inline static void foreach( state_type &x_tmp , const state_type &x , const boost::array< double , 1 > &a ,
            const state_type *k_vector , const double dt )
    {
        for( size_t i=0 ; i<x.size() ; ++i )
        {
            x_tmp[i] = x[i] + a[0]*dt*k_vector[0][i];
        }
    }

};


template<>
struct fusion_algebra< 2 >
{

    template< class state_type >
    inline static void foreach( state_type &x_tmp , const state_type &x , const boost::array< double , 2 > &a ,
            const state_type *k_vector , const double dt )
    {
        for( size_t i=0 ; i<x.size() ; ++i )
        {
            x_tmp[i] = x[i] + a[0]*dt*k_vector[0][i] + a[1]*dt*k_vector[1][i];
        }
    }

};


template<>
struct fusion_algebra< 3 >
{

    template< class state_type >
    inline static void foreach( state_type &x_tmp , const state_type &x , const boost::array< double , 3 > &a ,
            const state_type *k_vector , const double dt )
    {
        for( size_t i=0 ; i<x.size() ; ++i )
        {
            x_tmp[i] = x[i] + a[0]*dt*k_vector[0][i] + a[1]*dt*k_vector[1][i] + a[2]*dt*k_vector[2][i];
        }
    }

};

template<>
struct fusion_algebra< 4 >
{

    template< class state_type >
    inline static void foreach( state_type &x_tmp , const state_type &x , const boost::array< double , 4 > &a ,
            const state_type *k_vector , const double dt )
    {
        for( size_t i=0 ; i<x.size() ; ++i )
        {
            x_tmp[i] = x[i] + a[0]*dt*k_vector[0][i] + a[1]*dt*k_vector[1][i] +
                           a[2]*dt*k_vector[2][i] + a[3]*dt*k_vector[3][i];;
        }
    }

};
*/

#endif /* FUSION_ALGEBRA_HPP_ */
