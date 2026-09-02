#ifndef PARAMETER_DOCK_PLUGIN_COMMON_H
#define PARAMETER_DOCK_PLUGIN_COMMON_H

#define release_resource(function, resource) if ((resource) != nullptr) { function(resource); resource = nullptr; }

#endif //PARAMETER_DOCK_PLUGIN_COMMON_H
