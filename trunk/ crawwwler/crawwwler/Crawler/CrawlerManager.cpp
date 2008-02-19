#include "CrawlerPlugin.h"

#include "../Http/HttpUtils/HttpResponse.h"
#include "../Http/HttpUtils/HttpRequest.h"
#include "../DomainCrawler/DomainCrawler.h"

namespace Crawwwler
{

///////////////////////////////////////////////////////////////
// Constructors

CCrawlerPlugin::CCrawlerPlugin() {
	m_bStopRequest = false;
}

CCrawlerPlugin::~CCrawlerPlugin() {
}

///////////////////////////////////////////////////////////////
// Public Methods

bool CCrawlerPlugin::Init() {
	m_bStopRequest = false;
	// Not yet implemented
	return false;
}

bool CCrawlerPlugin::Start() {

	// ### Start the new thread here
	Crawl();

	// Not yet implemented
	return false;
}

bool CCrawlerPlugin::Stop() {
	// Not yet implemented
	return false;
}


///////////////////////////////////////////////////////////////
// Private Methods

void CCrawlerPlugin::Crawl() {

	// Run until we've had a stop request
	while (!m_bStopRequest) {
		// Prepare for the current cycle
		if (!PrepareNextCycle()) {
			// ### Put thread.sleep code here
			return;
		}

		if (!RunCycle()) {
			// ### Put thread.sleep code here
			return;
		}
	}
}

bool CCrawlerPlugin::RunCycle() {

	for (std::list<CUrl>::iterator i = m_CurrentUrls.begin(); i != m_CurrentUrls.end(); i++) {
		CUrl Current(*i);
		// Is this a resource-specific url or a '/' which means we should crawl the whole domain
		if (Current.GetResource() == "/") {
			if (!CrawlDomain(Current)) continue;
		} else {
			// We've been asked to fetch a specific resource
			if (!CrawlResource(Current)) continue;
		}
	}

	return true;
}

bool CCrawlerPlugin::CrawlDomain(const CUrl& Url) {
	CDomainCrawler DomainCrawler(Url.GetServer());
	if (!DomainCrawler.FetchRobotsFile()) {
		// Something went wrong, ignore this one
		return false;
	}
	return true;
}

bool CCrawlerPlugin::CrawlResource(const CUrl& Url) {
	// Not yet implemented
	return true;
}

bool CCrawlerPlugin::PrepareNextCycle() {

	// Clear the list of current urls
	m_CurrentUrls.clear();

	for (std::list<CUrl>::iterator i = m_TargetUrls.begin(); i != m_TargetUrls.end(); i++) {
		m_CurrentUrls.push_back(*i);
	}

	// Clear the list
	m_TargetUrls.clear();

	return true;
}

} // namespace GoldDigger