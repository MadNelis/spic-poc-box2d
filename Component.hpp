#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

namespace spic {

    /**
     * @brief Base class for all components.
     */
    class Component {
        public:
            /**
             * @brief Getter for active status.
             * @return true if active, false otherwise.
             */
            bool Active() const { return active; }

            /**
             * @brief flag New active status.
             */
            void Active(bool flag) { active = flag; }

            void setType(std::string type) {
                this->type = type;
            }

            std::string getType() {
                return this->type;
            }

        private:
            /**
             * @brief Active status.
             */
            bool active;

            std::string type;
    };

}

#endif // COMPONENT_H_
