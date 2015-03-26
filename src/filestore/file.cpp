

#include <string>

#include <config.h>
#include <utils.h>
#include <texture.h>
#include <filestore/file.h>



File::File(std::string file_path)
{
	path = file_path;
	texture = NULL;
}

File::~File()
{
	if(texture != NULL)
	{
		delete texture;
	}
}

void File::load()
{

}

void File::unload()
{

}

//extracts tags from the file's path and name
//splits a string on multiple delimeters
tag_set File::get_tags()
{
	tag_set tags;

	//copy the path, so to_lower won't affect the original
	std::string p = path;
	to_lower(p);

	size_t prev = 0;
	size_t pos = 0;

	//while there is another delimeter
    while((pos = p.find_first_of(config->tag_delim, prev)) != std::string::npos)
    {
        if(pos > prev)
        {
            tags.insert(p.substr(prev, pos-prev));
        }
        prev = pos + 1;
    }

    //add the last tag to the set
    if(prev < p.length())
    {
        tags.insert(p.substr(prev, std::string::npos));
    }

	return tags;
}