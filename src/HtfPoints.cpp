#include "bzfsAPI.h"

class HtfPoints : public bz_Plugin {
public:
  const char *Name() override;

  void Init(const char *config) override;

  void Cleanup() override;

  void Event(bz_EventData *eventData) override;
};

BZ_PLUGIN(HtfPoints)

const char *HtfPoints::Name() {
  return "HtfPoints 0.1.0";
}

void HtfPoints::Init(const char *config) {
  Register(bz_eCaptureEvent);
}

void HtfPoints::Cleanup() {
  Flush();
}

void HtfPoints::Event(bz_EventData *eventData) {
  if (eventData->eventType != bz_eCaptureEvent) {
    return;
  }

  const auto *data = dynamic_cast<bz_CTFCaptureEventData_V1 *>(eventData);
  const bz_eTeamType playerTeam = bz_getPlayerTeam(data->playerCapping);

  if (playerTeam != data->teamCapped) {
    return;
  }

  bz_incrementPlayerWins(data->playerCapping, 1);
  bz_incrementTeamWins(playerTeam, 1);
  bz_incrementTeamLosses(playerTeam, -1);

  bz_sendTextMessagef(BZ_SERVER, data->playerCapping, "You gain a point for capturing your own flag!");
}
