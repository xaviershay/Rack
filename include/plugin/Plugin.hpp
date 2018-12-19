#pragma once
#include "common.hpp"
#include <jansson.h>
#include <list>


namespace rack {


struct Model;


// Subclass this and return a pointer to a new one when init() is called
struct Plugin {
	/** A list of the models available by this plugin, add with addModel() */
	std::list<Model*> models;
	/** The file path of the plugin's directory */
	std::string path;
	/** OS-dependent library handle */
	void *handle = NULL;

	/** Must be unique. Used for patch files and the VCV store API.
	To guarantee uniqueness, it is a good idea to prefix the slug by your "company name" if available, e.g. "MyCompany-MyPlugin"
	*/
	std::string slug;
	/** The version of your plugin
	Plugins should follow the versioning scheme described at https://github.com/VCVRack/Rack/issues/266
	Do not include the "v" in "v1.0" for example.
	*/
	std::string version;
	/** Human readable name for your plugin, e.g. "Voltage Controlled Oscillator" */
	std::string name;
	std::string author;
	std::string license;
	std::string authorEmail;
	std::string pluginUrl;
	std::string authorUrl;
	std::string manualUrl;
	std::string sourceUrl;
	std::string donateUrl;

	virtual ~Plugin();
	void addModel(Model *model);
	Model *getModel(std::string slug);
	void fromJson(json_t *rootJ);
};


} // namespace rack
