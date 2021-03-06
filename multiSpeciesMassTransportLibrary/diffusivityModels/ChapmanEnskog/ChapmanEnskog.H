/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    Foam::binaryDiffusivityModels::ChapmanEnskog

Description
    ChapmanEnskog binary diffusivity model.
    
SourceFiles
    ChapmanEnskog.C

\*---------------------------------------------------------------------------*/

#ifndef ChapmanEnskog_H
#define ChapmanEnskog_H

#include "binaryDiffusivityModel.H"
#include "dimensionedScalar.H"
#include "volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace binaryDiffusivityModels
{

/*---------------------------------------------------------------------------*\
                           Class ChapmanEnskog Declaration
\*---------------------------------------------------------------------------*/

class ChapmanEnskog
:
    public binaryDiffusivityModel
{
    // Private data
    
        //- Constant of the model
        scalar A, B, C, DD, E, F, G, H;

        //- ...
        scalar E_ij, sigma_ij, W12;

        //- Conversion factor to convert the binary diffusivity coefficient
        //  in standard units (m^2/s)
        scalar phi;


public:

    //- Runtime type information
    TypeName("ChapmanEnskog");


    // Constructors

        //- construct from components
        ChapmanEnskog
        (
            const word& name1,
            const word& name2,
            const dictionary& dic,
            const volScalarField& p,
            const volScalarField& T
        );


    // Destructor

        ~ChapmanEnskog()
        {}


    // Member Functions

        //- Binary diffusion coefficient for patch [m^2/s]
        virtual tmp<scalarField> D
        (
            const scalarField& p,
            const scalarField& T,
            const label patchi
        ) const;

         //- Binary diffusion coefficient [m^2/s]
         virtual tmp<volScalarField> D() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace binaryDiffusivityModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
