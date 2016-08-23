#include "Common.h"

namespace SparCraft
{
    namespace System
    {
        bool UnitTypeSupported(const BWAPI::UnitType & type)
        {
            if (type == BWAPI::UnitTypes::None || type == BWAPI::UnitTypes::Unknown)
            {
                return false;
            }

            if (type.getRace() == BWAPI::Races::None)
            {
                return false;
            }

            if (type == BWAPI::UnitTypes::Protoss_Corsair || 
                type == BWAPI::UnitTypes::Zerg_Devourer || 
                type == BWAPI::UnitTypes::Zerg_Scourge ||
                type == BWAPI::UnitTypes::Terran_Valkyrie)
            {
                return false;
            }

            if (type.isBuilding() && !(type == BWAPI::UnitTypes::Protoss_Photon_Cannon || type == BWAPI::UnitTypes::Zerg_Sunken_Colony || type == BWAPI::UnitTypes::Terran_Missile_Turret))
            {
                return false;
            }

            if (type.isSpellcaster())
            {
                return false;
            }

            // Don't support units loading other units yet
            if (type == BWAPI::UnitTypes::Terran_Vulture_Spider_Mine || 
                type == BWAPI::UnitTypes::Protoss_Carrier || 
                type == BWAPI::UnitTypes::Protoss_Interceptor || 
                type == BWAPI::UnitTypes::Protoss_Reaver ||
                type == BWAPI::UnitTypes::Protoss_Scarab ||
                type == BWAPI::UnitTypes::Zerg_Broodling)
            {
                return false;
            }

            return true;
        }
    }

    namespace FileUtils
    {
        std::string ReadFile(const std::string & filename)
        {
            std::stringstream ss;

            FILE *file = fopen ( filename.c_str(), "r" );
            if ( file != NULL )
            {
                char line [ 4096 ]; /* or other suitable maximum line size */
                while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
                {
                    ss << line;
                }
                fclose ( file );
            }
            else
            {
                SPARCRAFT_ASSERT(false, "Couldn't open file: %s", filename.c_str());
            }
            return ss.str();
        }
    }
};
