#ifndef _MATERIAL_HEADER_
#define _MATERIAL_HEADER_

#include <vector>
#include <string>
#include <utility>
#include <memory>

#include "Nuclide.h"
#include "Particle.h"

class material {
  private:
    std::string material_name;
    double      material_atom_density;
    std::vector< std::pair< std::shared_ptr< nuclide >, double > > nuclides;

    double micro_xs(particle* p);
    double micro_xs(particle* p, std::string reaction_name);
  public:
     material( std::string label, double aden ) : material_name(label), material_atom_density(aden) {};
    ~material() {};

    std::string name() { return material_name; }
    double atom_density() { return material_atom_density; }
    std::vector< std::pair< std::shared_ptr< nuclide >, double > > getNuclides() { return nuclides; };

    void   addNuclide( std::shared_ptr< nuclide >, double );
    double macro_xs(particle* p);
    double macro_xs(particle* p, std::string reaction_name);

    std::shared_ptr< nuclide > sample_nuclide(particle* p);

    void sample_collision( particle* p, std::stack<particle>* bank );
};


#endif
