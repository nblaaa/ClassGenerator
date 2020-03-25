#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <memory>
#include <string>
#include <vector>

#include "AbstractClasses/Unit.h"

class ClassUnit: public Unit
{
public:
    enum AccessModifier {
         PUBLIC,
         PROTECTED,
         PRIVATE
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string& name): m_name(name) {
         m_fields.resize(ACCESS_MODIFIERS.size());
    }
    virtual void add(const std::shared_ptr<Unit>& unit, Flags flags) {
         int accessModifier = PRIVATE;
         if(flags < ACCESS_MODIFIERS.size()) {
              accessModifier = flags;
         }
         m_fields[accessModifier].push_back(unit);
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
    /*{
        std::string result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            result += ACCESS_MODIFIERS[ i ] + ":\n";
            for( const auto& f : m_fields[ i ] ) {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }*/
protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_H
