
/*
 * Copyright (C) 2000-2001 QuantLib Group
 *
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, contact ferdinando@ametrano.net
 * The license is also available at http://quantlib.sourceforge.net/LICENSE.TXT
 *
 * The members of the QuantLib Group are listed in the Authors.txt file, also
 * available at http://quantlib.sourceforge.net/Authors.txt
*/

/*! \file libormanager.hpp
    \brief global repository for %Libor histories

    $Id$
*/

// $Source$
// $Log$
// Revision 1.9  2001/06/05 09:35:13  lballabio
// Updated docs to use Doxygen 1.2.8
//
// Revision 1.8  2001/05/29 09:24:06  lballabio
// Using relinkable handle to term structure
//
// Revision 1.7  2001/05/28 16:12:12  lballabio
// *** empty log message ***
//
// Revision 1.5  2001/05/25 09:29:40  nando
// smoothing #include xx.hpp and cutting old Log messages
//
// Revision 1.4  2001/05/24 15:38:08  nando
// smoothing #include xx.hpp and cutting old Log messages
//

#ifndef quantlib_libor_manager_hpp
#define quantlib_libor_manager_hpp

#include "ql/history.hpp"
#include "ql/termstructure.hpp"
#include <map>

namespace QuantLib {

    namespace Indexes {

        //! global repository for libor histories
        class LiborManager {
          public:
            // historical fixings
            static void setHistory(const std::string& name, 
                int n, TimeUnit unit, const History&);
            static const History& getHistory(const std::string& name, 
                int n, TimeUnit unit);
            static bool hasHistory(const std::string& name, 
                int n, TimeUnit unit);
          private:
            static std::string tag(int n, TimeUnit unit);
            typedef std::map<std::string,History> HistoryMap;
            static HistoryMap historyMap_;
        };

    }

}


#endif
