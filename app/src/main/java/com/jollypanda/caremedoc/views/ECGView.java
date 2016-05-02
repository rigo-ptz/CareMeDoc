package com.jollypanda.caremedoc.views;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.View;

import java.util.LinkedList;
import java.util.Timer;

/**
 * View that shows grid and ecg signal.
 *
 * @author Yamushev Igor
 * @since 02.05.2016
 */
public class ECGView extends View {

    /** Standard speed of ecg grid moving. */
    private static final int ECG_STANDARD_SPEED = 40;

    /** Paint for draw view. */
    private Paint mPaint;

    /** Count of pixels in one millimeter. Used for drawing lines in grid. */
    private double mPpmm;

    /** Array for drawing signal */
    private double[] mSignalArray;

    /** Array for drawing grid*/
    private double [] gridOrigin;

    LinkedList<Double>  RRIntervals = new LinkedList<Double>();
    int iterator_ecg = 0;



    private int pulse;
    int maxX;
    int maxY;
    double squareSize;


    /** Quantity of dots on one ecg screen. */
    long ecgLengthScreenInDots = 0;

    /** Count of screens with ecg = length of mSignalArray / ecgLengthScreenInDots. */
    long screensWithEcgCount = 0;

    /** Number of current screen (starts from 1). 1st screen = from 0 дto ecgLengthScreenInDots and so on */
    int screenNumber = 0;

    public Timer myTimer;
    public Timer pulseTimer;

    int time = -1;


    /** Coordinate of first tap on view to swipe it. */
    private Coordinate startPoint;
    /** Coordinates while we swipe view, or when remove the finger from view. */
    private Coordinate endPoint;

    /** Swipe position. When we swipe to right it decrease to -infimum, when we swipe to left it increase to 0. */
    private double swipePosition = 0;

    /** Center of grid to draw signal. */
    private double gridCenterPosition;

    /**
     * @param context - context
     * @param ppmm - pixel per millimeter
     */
    public ECGView(Context context, double ppmm) {
        super(context);

        mPaint = new Paint();

        gridOrigin = new double[2];
        gridOrigin[0] = 0;
        gridOrigin[1] = 0;

        startPoint = new Coordinate(0,0);
        endPoint = new Coordinate(0,0);

        mPpmm = ppmm;
        squareSize =  6 + 5 * ppmm;
    }

    @Override
    public boolean onTouchEvent(MotionEvent ev) {

        switch (ev.getAction()) {
            case MotionEvent.ACTION_DOWN:
                startPoint.x = ev.getX();
                startPoint.y = ev.getY();
                if (screenNumber >= screensWithEcgCount) {
                    break;
                }
                break;
            case MotionEvent.ACTION_MOVE:
                endPoint.x = ev.getX();
                endPoint.y = ev.getY();
                //Log.i("ACTION_MOVE END POINT", String.valueOf(endPoint.x) + " " +String.valueOf(endPoint.y) + " " +String.valueOf(startPoint.x));
                double diff = endPoint.x - startPoint.x;
                //Log.i(" diff1", String.valueOf(diff));
                // due to stop moving on last screen
                screenNumber = (int) Math.abs(Math.floor(-Math.min(swipePosition + diff, 0) / getWidth())) + 1;
                if (screenNumber >= screensWithEcgCount) {
                    break;
                }
                startPoint.x = endPoint.x;
                //Log.i("START END POINTS", String.valueOf(startPoint.x) + " " +String.valueOf(endPoint.x));
                //Log.i("swipePosition","MOVE BEFORE  " +  String.valueOf(swipePosition));
                swipePosition = Math.min(swipePosition + diff, 0);
                //Log.i("screenNumber",  String.valueOf(screenNumber));
                //Log.i("swipePosition", "MOVE AFTER  " +  String.valueOf(swipePosition));
                gridOrigin[0] = swipePosition;  // +10
                //Log.i("gridOrigin MOVE", String.valueOf(gridOrigin[0]));
                invalidate();
                break;
            case MotionEvent.ACTION_UP:
                endPoint.x = ev.getX();
                endPoint.y = ev.getY();
                double diff1 = endPoint.x - startPoint.x;
                screenNumber = (int) Math.abs(Math.floor(-Math.min(swipePosition + diff1, 0) / getWidth())) + 1;
                if (screenNumber >= screensWithEcgCount) {
                    break;
                }
                //Log.i("swipePosition","UP BEFORE  " +  String.valueOf(swipePosition));
                swipePosition = Math.min(swipePosition + diff1, 0);
                //Log.i("swipePosition","UP AFTER  " +  String.valueOf(swipePosition));
                gridOrigin[0] = swipePosition; // +10
                //Log.i("gridOrigin[0] UP", String.valueOf(gridOrigin[0]));
                //Log.i("END UP", String.valueOf(x) + " " +String.valueOf(y));
                invalidate();
                break;
        }
        return true;
    }

    @Override
    protected void onSizeChanged(int xNew, int yNew, int xOld, int yOld) {
        maxX = xNew;
        maxY = yNew;

        ecgLengthScreenInDots = Math.round(getWidth()/(2 * squareSize / 72.0)); // 50
        //Log.i("ecgLengthScreenInDots", String.valueOf(ecgLengthScreenInDots));

        screenNumber = (int) Math.abs(Math.floor(-swipePosition / getWidth())) + 1;

        screensWithEcgCount = mSignalArray.length / ecgLengthScreenInDots + 1;
        //Log.i("screensWithEcgCount", String.valueOf(screensWithEcgCount));

        super.onSizeChanged(xNew, yNew, xOld, yOld);
    }

    @Override
    public void onDraw(Canvas canvas) {
        mPaint.setStyle(Paint.Style.FILL);
        mPaint.setSubpixelText(true);
        mPaint.setAntiAlias(true);

        mPaint.setColor(Color.WHITE);
        canvas.drawPaint(mPaint);

        drawGrid(canvas);

        drawSignal(canvas, mSignalArray, screenNumber);

        //paint.setColor(Color.WHITE);
        //paint.setTextSize(24);
        //canvas.drawText(new Integer(pulse).toString(), 10, 25, paint);
    }

    public void drawSignal(Canvas canvas, double[] signal, int screenNumber) {

        gridCenterPosition = getHeight() / 2;
        mPaint.setColor(Color.BLACK);
        mPaint.setStrokeWidth(4);

        double x0 = gridOrigin[0];
        double y0 = gridCenterPosition - signal[0] * 2 * squareSize / 1000.0 + 0.5;
        //  double y0 = gridCenterPosition - signal[screenNumber * (int) ecgLengthScreenInDots - (int) ecgLengthScreenInDots] * 2 * squareSize / 1000.0 + 0.5;

        /*
         * Чтобы не пересчитывать большие массивы на каждом отсчете координаты, пересчитываем
         * только от начала текущего экрана и до конца следующего.
         * Листание назад обеспечивается все тем же номером экрана и gridOrigin.
         * Индекс работает нормально. При 2 экране от 696 до 2087,
         * при первом соотв-нно от 0 до 695 (просто пример, на эмуляторе)
         */
//TODO у0 все равно от начального надо сделать от текущего !!!!!!!!!!!!!!! либо вынести x0 y0
        for (int i = screenNumber * (int) ecgLengthScreenInDots - (int) ecgLengthScreenInDots; (i < (screenNumber + 1) * (int) ecgLengthScreenInDots) && (i < signal.length); i++) {

            double x = gridOrigin[0] + i * 2 * squareSize / 72.0; //50 72 360
            //Log.i("drawSignal X Y", String.valueOf(i) + "  " + String.valueOf(x) + "  " + String.valueOf(gridOrigin[0]));
            double y = gridCenterPosition - signal[i] * 2 * squareSize / 1000.0 + 0.5;
            canvas.drawLine((float)x0, (float)y0, (float)x, (float)y, mPaint);
            x0 = x;
            y0 = y;
        }
    }

    public void drawGrid(Canvas canvas) {
        int leftColumn = (int)Math.round(-gridOrigin[0] / squareSize) - 1;
        // Log.i("drawGrid leftColumn", String.valueOf(leftColumn));
        int rightColumn = (int)Math.ceil(leftColumn + getWidth() / squareSize) + 2;

        //int topRow = (int)Math.round(-gridOrigin[1] / squareSize);
        //int bottomRow = (int)Math.ceil(topRow + getHeight() /(squareSize)) + 1;

        int bottomRow = (int)Math.ceil(getHeight() /(squareSize));

        for (int row = 0; row < bottomRow; row++) {
            for (int column = leftColumn; column < rightColumn; column++) {
                drawSquare(canvas, row, column);
            }
        }
  /*     //Можно использовать это, чтобы сетка не двигалась
        int leftColumn = (int)Math.round(-gridOrigin[0] / squareSize);
        int rightColumn = (int)Math.round(leftColumn + getWidth() / (squareSize)) + 1;

        int topRow = (int)Math.round(-gridOrigin[1] / squareSize);
        int bottomRow = (int)Math.round(topRow + getHeight() /(squareSize)) + 1;

        double i  = (ppmm * 5-6)/5;

        double maxRow = getHeight() / ppmm;
        double maxColumn = getWidth() / ppmm;

        long strokeLine = Math.round(i * 5 + 2);

        // 1 mm lines
        paint.setColor(Color.RED);
        paint.setStrokeWidth(1);
        for(int x = 0; x < maxColumn + 1; x++)
            canvas.drawLine((float)(x* getWidth() / maxColumn), 0, (float)(x* getWidth() / maxColumn), getHeight(), paint);
        for(int y = 0; y < maxRow + 1; y++)
            canvas.drawLine(0, (float)(y* getHeight() / maxRow), getWidth(), (float)(y* getHeight() / maxRow), paint);

        // 5 mm lines
        paint.setColor(Color.RED);
        paint.setStrokeWidth(3);
        double max5Row = maxRow/5;
        double max5Column = maxColumn/5;
        for(int x = 0; x < (int)max5Column + 1; x++)
            canvas.drawLine((float)(x* getWidth() / max5Column), 0, (float)(x* getWidth() / max5Column), getHeight(), paint);
        for(int y = 0; y < (int)max5Row + 1; y++)
            canvas.drawLine(0, (float)(y* getHeight() / max5Row), getWidth(), (float)(y* getHeight() / max5Row), paint);*/

    }

    public void drawSquare(Canvas canvas, int row, int column) {

        //int topRow = (int)Math.round(-gridOrigin[1] / squareSize);
        //int bottomRow = (int)Math.ceil(topRow + getHeight() /(squareSize)) + 1;
        int bottomRow = (int)Math.ceil(getHeight() /(squareSize));

        double x = gridOrigin[0] + column * squareSize + 0.5;
        double y = gridOrigin[1] + row * squareSize + 0.5;

        if (column % 2 == 0) {
            //Log.i("drawGrid column", String.valueOf(column));
            mPaint.setColor(Color.BLACK);
            mPaint.setTextSize(30);
            canvas.drawText(String.valueOf(column / 2), (float) x - 10, 25, mPaint); // time
        }

        mPaint.setColor(Color.RED);
        mPaint.setStrokeWidth(1);

        for (int i = 0; i <  bottomRow; i++) {
            if (i % 5 == 0) {
                mPaint.setStrokeWidth(3);
            } else{
                mPaint.setStrokeWidth(1);
            }
            double lineOffset = i * (mPpmm + 1);
            double lineLength = squareSize - 1;
            canvas.drawLine((float)x, (float)(y + lineOffset), (float)(x + lineLength), (float)(y + lineOffset), mPaint);
            canvas.drawLine((float)(x + lineOffset), (float)y, (float)(x + lineOffset), (float)(y + lineLength), mPaint);
        }
    }

    public void setECGData(int[] signalArray) {
        mSignalArray = new double[signalArray.length];
        for (int i =0; i < signalArray.length; i++) {
            mSignalArray[i] = (double) signalArray[i];
        }
    }

    private class Coordinate {
        double x;
        double y;
        public Coordinate(double xx, double yy) {
            this.x = xx;
            this.y = yy;
        }
    }
}
