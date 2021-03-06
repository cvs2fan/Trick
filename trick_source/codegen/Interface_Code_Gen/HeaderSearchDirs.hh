
#ifndef _HEADER_SEARCH_DIRS_HH_
#define _HEADER_SEARCH_DIRS_HH_

#include <map>
#include <vector>
#include <string>

#include "clang/Lex/HeaderSearch.h"
#if (__clang_major__ == 3) && (__clang_minor__ >= 3)
#include "clang/Lex/HeaderSearchOptions.h"
#else
#include "clang/Frontend/HeaderSearchOptions.h"
#endif
#include "clang/Lex/Preprocessor.h"

/**

  This class gathers all of the include directories and adds them to the preprocessor
  to use. Include directories are built into the compiler, inclded on the command line, or
  added by Trick itself.

  @author Alexander S. Lin

  @date July 2012

 */

class HeaderSearchDirs {

    public:
        HeaderSearchDirs(clang::HeaderSearch & in_hs ,
                         clang::HeaderSearchOptions & in_hso ,
                         clang::Preprocessor & in_pp ,
                         bool in_sim_services ) ;

        /** Add all search directories to the preprocessor.
            @param include_dirs = directories incuded on the command line
          */
        void addSearchDirs ( std::vector<std::string> & include_dirs ) ;

        /** Returns true if the path argument is in a user model directory
            @param path = directory path to be checked
            @return true = path is in user directory, false = path is not in a user dir.
          */
        bool isPathInUserDir (std::string path) ;

        /** Returns true if the path argument is in a user model or Trick directory
            @param path = directory path to be checked
            @return true = path is in user directory, false = path is not in a user dir.
          */
        bool isPathInUserOrTrickDir (std::string path) ;

        /** Returns true if directory is a subdirectory of an excluded directory listed
            in the TRICK_ICG_EXCLUDE environment variable.
            @param path = directory path to be checked
            @return true = path is in a system directory, false = not in system directory.
          */
        bool isPathInICGExclude (std::string path) ;

        /** Returns true if directory is a subdirectory of a no comment directory
            in the TRICK_ICG_NOCOMMENT environment variable.
            @param path = directory path to be checked
            @return true = path is in a system directory, false = not in system directory.
          */
        bool isPathInICGNoComment (std::string path) ;

        /** Returns the TRICK_ICG_EXCLUDE directory that contains the path argument.
            @param path = path to be checked
            @return string from TRICK_ICG_EXCLUDE that contains the path.
          */
        std::string getPathInICGExclude (std::string path) ;

        /** Add all #defines from the command line and built in default predefines
            @param defines = a list of all -D<define> arguments on the command line.
          */
        void addDefines ( std::vector<std::string> & defines ) ;

    private:
        /** Are we ICG'ing the sim_services files? */
        bool sim_services ;

        /** The compiler's header search class.  We are filling this class with our directories. */
        clang::HeaderSearch & hs ;

        /** The compiler's header search options class.  We are filling this class with our directories. */
        clang::HeaderSearchOptions & hso ;

        /** The compiler's preprocessor */
        clang::Preprocessor & pp ;

        /** ${TRICK_HOME}/trick_source resolved */
        std::string trick_source_dir ;

        /** Adds all of the built-in system paths contained in the TRICK_CPPC compiler */
        void AddCompilerBuiltInSearchDirs () ;

        /** Adds all of the paths specified on the command line */
        void AddUserSearchDirs ( std::vector<std::string> & include_dirs ) ;

        /** Adds ${TRICK_HOME}/trick_source to the search directories */
        void AddTrickSearchDirs () ;

        /** Create list of ICG_EXCLUDE directories  */
        void AddICGExcludeDirs () ;

        /** Create list of ICG_NOCOMMENT directories  */
        void AddICGNoCommentDirs () ;

        /** Apply all search directories to the preprocessor. */
        void ApplyHeaderSearchOptions () ;

        /** List of directoris to exclude from the TRICK_ICG_EXCLUDE environment variable */
        std::vector<std::string> icg_exclude_dirs ;

        /** List of directoris to exclude comments from the TRICK_ICG_NOCOMMENT environment variable */
        std::vector<std::string> icg_nocomment_dirs ;

        /** Map of file names to in icg_nocomment_dir used as a cache */
        std::map< std::string , bool > icg_nocomment_files ;
} ;

#endif
