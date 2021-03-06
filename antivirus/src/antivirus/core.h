#ifndef __ANTIVIR_CORE_H__
#define __ANTIVIR_CORE_H__

#include <string>
 
#include "database.h"
#include "filedata.h"

#define ANTIVIR_SANDBOX_DIR	"./sandbox"

namespace antivirus
{
	/**
	* Class controlling antivirus behaviour
	*/
	class Core
	{
		public:
			Core() throw(DatabaseException);
			Core(const std::string& database_filename) throw(DatabaseException);
			virtual ~Core();

			enum E_RETURN_CODE
			{
				E_FAILED,
				E_VIRUS_SPOTTED,
				E_LOOKS_CLEAN
			};

			E_RETURN_CODE perform_static_check(const std::string& filename);
			E_RETURN_CODE perform_dynamic_check(const std::string& filename);

		private:
			Database _database;

			bool _check_signatures(FileData* data);

			E_RETURN_CODE _dynamic_check_by_hijacking(const std::string& filename);
			E_RETURN_CODE _dynamic_check_by_tracing(const std::string& filename);
	};
}

#endif
