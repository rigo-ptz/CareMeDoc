package com.jollypanda.caremedoc.interfaces;

/**
 * Interface to notify an item ViewHolder of relevant callbacks from {@link
 * android.support.v7.widget.helper.ItemTouchHelper.Callback}.
 *
 * @author Yamushev Igor
 * @since 24.04.2016
 */
public interface OnItemTouchHelperViewHolder {
    /**
     * Called when the {@link OnItemTouchHelper} first registers an item as being moved or swiped.
     * Implementations should update the item view to indicate it's active state.
     */
    void onItemSelected();


    /**
     * Called when the {@link OnItemTouchHelper} has completed the move or swipe, and the active item
     * state should be cleared.
     */
    void onItemClear();
}
