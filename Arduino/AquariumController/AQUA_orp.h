/*
  Project: Aquarium Controller
  Library: ORP
  Version: 1.0
  Author: Rastislav Birka
*/

#ifndef AQUA_orp_h
#define AQUA_orp_h

typedef struct {
  bool state;
  int refValue;
  int actValue;
} AQUA_orpCalibrationPoint;

class AQUA_orp {
  public:
    void init(uint8_t dqPin, uint8_t calibrate_points, uint8_t calibrate_address);
    int getORP(bool calibrate = 0);
    bool calibration(uint8_t point, AQUA_orpCalibrationPoint *values);
    AQUA_orpCalibrationPoint readCalibrationPoint(uint8_t point);

  private:
    uint8_t _dqPin;
    uint8_t _pointCount;
    uint8_t _calibrateAddress;
    AQUA_orpCalibrationPoint* _calData;
    AQUA_orpCalibrationPoint* _usedData;
    uint8_t _usedPoints;
    float* _const;

    void _setCalibrationValues();
};
#endif
