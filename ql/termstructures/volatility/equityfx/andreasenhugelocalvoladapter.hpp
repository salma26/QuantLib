/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2017, 2018 Klaus Spanderen

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file andreasenhugelocalvolatilityadapter.hpp
    \brief Implements the LocalVolTermStructure interface based on a
           Andreasen-Huge volatility interpolation
*/

#ifndef quantlib_andreasen_huge_local_volatility_adapter_hpp
#define quantlib_andreasen_huge_local_volatility_adapter_hpp

#include <ql/termstructures/volatility/equityfx/localvoltermstructure.hpp>

namespace QuantLib {

    class AndreasenHugeVolatilityInterpl;

    class AndreasenHugeLocalVolAdapter : public LocalVolTermStructure {
      public:
        explicit AndreasenHugeLocalVolAdapter(
            const boost::shared_ptr<AndreasenHugeVolatilityInterpl>& localVol);

        void update();

        Date maxDate() const;
        Real minStrike() const;
        Real maxStrike() const;

      protected:
        Volatility localVolImpl(Time t, Real strike) const;

      private:
        const boost::shared_ptr<AndreasenHugeVolatilityInterpl> localVol_;
    };
}


#endif
